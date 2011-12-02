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
//      if ($key == 'cc') {
//        $form['payment_methods'][$key]["{$key}_submit"]['#ajax'] = array(
//          'callback' => 'buckaroo_cc_ajax',
//          'wrapper' => 'ajax-wrapper',
//          'method' => 'replace',
//          'effect' => 'fade',
//        );
//      };

      if (!empty($method['description'])) {
        $form['payment_methods'][$key]['description'] = array(
          '#markup' => $method['description'],
        );
      }
    }
  }
// TMP disabled, planned ajax connection
//  $form['ajax_wrapper'] = array(
//    '#type' => 'container',
//    '#weight' => empty($vars['civi_position']) ? 1 : $vars['civi_position'],
//    '#attributes' => array(
//      'id' =>'ajax-wrapper',
//     ),
//  );

  if (module_exists('civi_api') && !empty($vars['civi_profile'])) {
    $contact_id = civi_get_contact_id();

    $form['crm'] = array(
      '#prefix' => !empty($vars['civi_title']) ? "<h3>{$vars['civi_title']}</h3>" : NULL,
      '#markup' => civi_get_profile_form($contact_id, $vars['civi_profile']),
      '#attributes' => array(
        'class' => array('civicrm'),
       ),
      '#weight' => $vars['civi_position'],
    );
  }

  //$form['#submit'] = array('buckaroo_payment_form_submit');
  //dsm(get_defined_vars());
  $form += buckaroo_get_hidden_elements();
  return $form;
}

function buckaro_cc_ajax($form, $form_state) {
  return $form['payment_methods'];
}

function buckaroo_payment_form_validate($form, &$form_state) {
  $form_state['values']['value'] = 1;
}

//function buckaroo_payment_form_submit($form, &$form_state) {
  //$form_state['values']['value'] = 1;
  //dsm(get_defined_vars());
//}

function buckaroo_get_hidden_elements($machine_name = NULL) {
  $vars = buckaroo_variable_get();
  //Look at BPE_Return_Method
  $need_post_method = array('pp', 'ideal');
  $return = array();

  global $base_url;
  $path = $base_url . '/buckaroo';

  $elements = array(
    //The merchant key you received from Buckaroo. This code ensures that the transaction is credited to your
    //account. If you have more than one website, you will have received several unique merchant keys:
    //one for each website. *
    'BPE_Merchant' => array(
      '#type' => 'hidden',
      '#value' => $vars['merchant_key'],
      'used' => array (
        'all'
      )
    ),
    //The transaction amount in cents. *
    'BPE_Amount' => array(
      '#type' => 'hidden',
      '#value' => isset($_GET['default_amount']) ? $_GET['default_amount'] * 100 : $vars['amount_values'][0] * 100,
      '#attributes' => array(
        'class' => 'BPE_Amount'
      ),
      'used' => array (
        'all'
      )
    ),
    //The code for the currency in which the transaction is to be made. *
    'BPE_Currency' => array(
      '#type' => 'hidden',
      //Ideal only supports EUR
      '#value' => $machine_name == 'ideal' ? 'EUR' : $vars['currency'],
      'used' => array (
        'all'
      )
    ),
    //The code of the preselected bank in this field. If this value is specified, Buckaroo‟s selection creen will not appear. Your customer will be redirected to the bank‟s screen instead.
    //tmp diabled
//    'BPE_Issuer' => array(
//      '#type' => 'hidden',
//      '#value' => '',
//      'used' => array (
//        'ideal'
//      )
//    ),
    //short transaction description.
    'BPE_Description' => array(
      '#type' => 'hidden',
      '#value' => $vars['description'],
      'used' => array (
        'all'
      )
    ),
    //Language code for the user interface language:NL = Dutch EN = English;
    'BPE_Language' => array(
      '#type' => 'hidden',
      '#value' => 'EN',
      'used' => array (
        'all'
      )
    ),
    //Parameter mode: 0 = full processing 1 = test mode
    'BPE_Mode' => array(
      '#type' => 'hidden',
      '#value' => $vars['mode'],
      'used' => array (
        'all'
      )
    ),
    //The digital signature to authenticate your website as sender. *
    'BPE_Signature2' => array(
      '#type' => 'hidden',
      '#value' =>  buckaroo_create_signature($machine_name),
      'used' => array (
        'all'
      )
    ),
    //Specify a different URL for the return page for successful payments.
    'BPE_Return_Success' => array(
      '#type' => 'hidden',
      '#value' => $vars['success_path'],
      'used' => array (
        'all'
      )
    ),
    //Specify a different URL for the return page for payments rejected by PayPal (processor).
    'BPE_Return_Reject' => array(
      '#type' => 'hidden',
      '#value' => $vars['error_path'],
      'used' => array (
        'all'
      )
    ),
    //Specify a different URL for the return page for payments that cannot be processed due to a technical malfunction.
    'BPE_Return_Error' => array(
      '#type' => 'hidden',
      '#value' => $vars['error_path'],
      'used' => array (
        'all'
      )
    ),
    //Specify how result parameters should be passed to your response pages:
    'BPE_Return_Method' => array(
      '#type' => 'hidden',
      '#value' => 'POST',
      'used' => array (
        'all'
      )
    ),
    'BPE_Reference' => array(
      '#type' => 'hidden',
      '#value' => 'test',
      'used' => array (
        'all'
      )
    ),
    'BPE_Invoice' => array(
      '#type' => 'hidden',
      '#value' => buckaroo_create_invoice(),
      'used' => array (
        'all'
      )
    ),
  );

  foreach ($elements as $key => $element) {
    if (in_array($machine_name, $element['used']) || in_array('all', $element['used'])) {
      unset($element['used']);
      $return[$key] = $element;
    }
  }
  dsm(get_defined_vars());
  return $return;
}

