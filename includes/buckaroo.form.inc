<?php

function buckaroo_payment_form($form_state) {
  $form = array();
  $values = array();
  $vars = buckaroo_variable_get();

  drupal_add_js(drupal_get_path('module', 'buckaroo') . '/js/buckaroo.js');

  foreach ($vars['amount_values'] as $value) {
    $values[$value] = $value . ' ' . $vars['currency'];
  }

  $form['amount'] = array(
    '#prefix' => !empty($vars['amount_title']) ? "<h3>{$vars['amount_title']}</h3>" : NULL,
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('amount')
     ),
    '#weight' => 0.5,
    'value' => array(
      '#type' => 'radios',
      '#default_value' => isset($_GET['default_amount']) ? $_GET['default_amount'] : $vars['amount_values'][0],
      '#options' => $values,
    ),
  );

  if ($vars['unique_amount'] != '') {
    $form['amount']['uniqueamount'] = array(
      '#type' => 'textfield',
      '#title' => $vars['unique_amount'],
      '#size' => 15,
      '#field_suffix' => $vars['currency'],
    );
  }

  $form['payment_methods'] = array(
    '#prefix' => !empty($vars['method_title']) ? "<h3>{$vars['method_title']}</h3>" : NULL,
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('payment-methods'),
     ),
    '#weight' => 1.5,
  );

  foreach (buckaroo_get_payment_methods() as $key=>$method) {
    if ($method['enabled']) {
      $form['payment_methods'][$key] = array(
        '#type' => 'item',
        '#title' => $method['name'],
        "{$key}_submit" => array(
          '#name' => $key,
          '#type' => 'submit',
          '#value' => $method['name'],
          '#attributes' => array(
            'id' => "{$key}_submit",
          ),
        ),
      );

      if (!empty($method['description'])) {
        $form['payment_methods'][$key]['description'] = array(
          '#markup' => $method['description'],
        );
      }
    }
  }

  if (module_exists('civi_api') && !empty($vars['civi_profile'])) {
    $contact_id = civi_get_contact_id();
    global $user;

    $form['#user'] = $user;
    $form_state['user'] = $user;
    civicrm_key_disable( );
    //$form['#attributes']['enctype'] = 'multipart/form-data';

    if ($user->uid > 0) {
      $options = array(
        'process' => TRUE,
        'action' => 2,
      );
    }
    else {
      $options = array(
        'process' => TRUE,
        'action' => 1,
      );
    }


    $form['crm'] = array(
      '#prefix' => !empty($vars['civi_title']) ? "<h3>{$vars['civi_title']}</h3>" : NULL,
      '#markup' => civi_get_profile_form($contact_id, $vars['civi_profile'], $options),
      '#attributes' => array(
        'class' => array('civicrm'),
       ),
      '#weight' => $vars['civi_position'],
    );
  }

  dsm(get_defined_vars());
  return $form;
}

function buckaroo_payment_form_validate($form, &$form_state) {
  $valid = &drupal_static(__FUNCTION__);
  if (isset($valid)) {
    return ;
  }
  $valid = TRUE;

  // lets suppress key generation for all validation also
  civicrm_key_disable();

  require_once 'CRM/Utils/Array.php';
  require_once 'CRM/Core/BAO/UFMatch.php';
  require_once 'CRM/Core/BAO/UFGroup.php';

  $uid = civi_get_contact_id($form['#user']->uid);

  // The main CiviCRM form validate process.
  $errors = CRM_Core_BAO_UFGroup::isValid($uid, '', TRUE);

  if (is_array($errors)) {
    foreach ($errors as $name => $error) {
      form_set_error($name);
    }
  }

  // Because of civicrm validation bug, civicrm doesn't pass email-Primary error into $errors array
  if (isset($form_state['input']['email-Primary']) && !valid_email_address($form_state['input']['email-Primary'])) {
    form_set_error('email-Primary');
  }

//  @todo let's start to build a drupal user??
//  $account = $form['#user'];
//  entity_form_submit_build_entity('user', $account, $form, $form_state);

//  return true;
}

function buckaroo_payment_form_submit($form, &$form_state) {
  $form_state['redirect'] = url('buckaroo/confirm', array('absolute' => TRUE, 'query' => array($form_state['input'])));
}
