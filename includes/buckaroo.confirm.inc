<?php

function buckaroo_confirm_form($form_state) {
  $form = array();
  $values = array();
  $vars = buckaroo_variable_get();

  foreach (buckaroo_get_payment_methods() as $key=>$method) {
    if (!empty($_GET[$key])) {
      $payment_method = $method;
      $payment_method_key = $key;
    }
  }

  $form['pre'] = array(
    '#markup' => t('Are you sure to start payment? You will be redirected to Buckaroo payment gateway based on selected payment method'),
  );

  $form['payment_method'] = array (
    '#type' => 'item',
    '#markup' => $payment_method['name'],
    '#title' => t('Payment method') . ': ',
  );

  $form['amount'] = array (
    '#type' => 'item',
    '#markup' => is_numeric($_GET['uniqueamount']) ? $_GET['uniqueamount'] : $_GET['value'],
    '#title' => t('Amount') . ': ',
    '#field_suffix' => $vars['currency'],
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  if (module_exists('civi_api')) {
    $form['email'] = array(
      '#type' => 'hidden',
      '#value' => $_GET['email-Primary'],
    );
  }

  $form += buckaroo_get_hidden_elements($payment_method_key);
  $form['#action'] = $payment_method['action'];
  return $form;
}

