<?php

/**
 * @file
 * Settings for Buckaroo payment page.
 */

function buckaroo_admin_form($form_state) {
  $form = array();
  $vars = buckaroo_variable_get();

  $form['basic'] = array(
    '#type' => 'fieldset',
    '#title' => t('Buckaroo basic data'),
  );

  $form['basic']['BPE_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path'),
    '#default_value' => $vars['path'],
    '#size' => 40,
    '#description' => t('Specify a relative URL to show Buckaroo payment form. Use "node/[nid]" path, if you want to attach form to a node.'),
    '#field_prefix' => url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
    '#required' => TRUE,
  );
  $form['basic']['BPE_Merchant'] = array(
    '#type' => 'textfield',
    '#title' => t('Merchant key'),
    '#default_value' => $vars['merchant_key'],
    '#size' => 60,
    '#description' => t('The merchant key of website.'),
    '#required' => TRUE,
  );
  $form['basic']['BPE_SecretKey'] = array(
    '#type' => 'textfield',
    '#title' => t('Secret key'),
    '#default_value' => $vars['secret_key'],
    '#size' => 60,
    '#description' => t('The secret key of website.'),
    '#required' => TRUE,
  );
  $form['basic']['BPE_Description'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#default_value' => $vars['description'],
    '#size' => 60,
    '#description' => t('Short description will be shown on transaction pages.'),
    //'#required' => TRUE,
  );
  $form['basic']['BPE_success_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Success page'),
    '#default_value' => $vars['success_path'],
    '#size' => 40,
    '#description' => t('Specify a relative URL to redirect after payment is successful.'),
    '#field_prefix' => url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
  );
  $form['basic']['BPE_error_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Error page'),
    '#default_value' => $vars['error_path'],
    '#size' => 40,
    '#description' => t('Specify a relative URL to redirect after payment is failed.'),
    '#field_prefix' => url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
  );

  $form['amount'] = array(
    '#type' => 'fieldset',
    '#title' => t('Ammount selection settings'),
  );
  $form['amount']['BPE_amount_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title of amount selection section'),
    '#default_value' => $vars['amount_title'],
    '#size' => 60,
    '#description' => t('Specify a the title of amount selection section.'),
  );
  $form['amount']['BPE_amount_values'] = array(
    '#title' => t('Amount values'),
    '#type' => 'textarea',
    '#description' => t('Need some text'),
    '#default_value' => drupal_implode_tags($vars['amount_values']),
  );
  $form['amount']['BPE_amount_curr'] = array(
    '#type' => 'textfield',
    '#title' => t('Currency'),
    '#default_value' => $vars['currency'],
    '#size' => 5,
  );
  $form['amount']['BPE_unique_amount'] = array(
    '#type' => 'textfield',
    '#title' => t('Unique amount text'),
    '#default_value' => $vars['unique_amount'],
    '#size' => 60,
    '#description' => t('Title of unique amount textfield. Leave empty, if unique amount field is not necessary.'),
  );

  $form['method'] = array(
    '#type' => 'fieldset',
    '#title' => t('Enabled payment methods'),
  );
  $form['method']['buckaroo_method_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title of payment method section'),
    '#default_value' => $vars['method_title'],
    '#size' => 60,
    '#description' => t('Specify a the title of payment method selection section.'),
  );

  foreach (buckaroo_get_payment_methods() as $key => $value) {
    $form['method']["BPE_{$key}_enabled"] = array(
      '#type' => 'checkbox',
      '#title' => t($value['name']),
      '#default_value' => $value['enabled'],
    );
  }

  if (module_exists('civi_api')) {
    $form['civicrm'] = array(
      '#type' => 'fieldset',
      '#title' => t('Civicrm settings'),
    );
    $profiles = array('none' => ' - ' . t('Select a Profile') . ' - '); //Initialize array for selector options
    $profiles += civi_get_profiles();

    $form['civicrm']['BPE_civi_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title of Civicrm profile'),
      '#default_value' => $vars['civi_title'],
      '#size' => 60,
      '#description' => t('Specify a the title of CiviCRM profile form.'),
    );

    $form['civicrm']['BPE_civi_profile'] = array(
      '#type' => 'select',
      '#title' => t('CiviCRM profile'),
      '#options' => $profiles,
      '#default_value' => $vars['civi_profile'],
    );

    $form['civicrm']['BPE_civi_position'] = array(
      '#type' => 'select',
      '#title' => t('Position'),
      '#options' => array(t('Top'), t('Middle'), t('Bottom')),
      '#default_value' => $vars['civi_position'],
    );
  }

  $form['BPE_Mode'] = array(
    '#type' => 'checkbox',
    '#title' => t('Test mode'),
    '#default_value' => $vars['mode'],
    '#description' => t('Transactions are registered with Buckaroo, but not forwarded to the provider. When we receive your transaction in good order, you will immediately be directed to the specified success page.'),
  );

  return system_settings_form($form);
}

function buckaroo_admin_form_validate($form, &$form_state) {
  $form_state['values']['BPE_amount_values'] = drupal_explode_tags($form_state['values']['BPE_amount_values']);
}

function buckaroo_admin_form_submit($form, &$form_state) {
  //Rebuild menu, if path changed.
  if ($form['buckaroo_path']['#default_value'] != $form_state['values']['buckaroo_path']) {
    menu_rebuild();
  }
}