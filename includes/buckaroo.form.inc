<?php

function buckaroo_payment_form($form_state) {
  $form['amount'] = array(
    '#type' => 'fieldset',
    '#title' => variable_get('buckaroo_amount_title', 'Choose an ammount'),
  );
  return $form;
}

function buckaroo_amount_form($form_state) {
  $form = array();
  $values = array();
  $currency = variable_get('buckaroo_amount_curr', 'EUR');
  $var_values = variable_get('buckaroo_amount_values', array('5', '10', '*'));
  $unique_amount = variable_get('buckaroo_unique_amount', '');


  foreach ($var_values as $value) {
    if ($value != '*') {
      $values[$value] = $value . ' ' . $currency;
    }
  }

  $form['amount'] = array(
    '#type' => 'radios',
    '#default_value' => isset($_GET['default_amount']) ? $_GET['default_amount'] : $var_values[0],
    '#options' => $values,
  );

  if ($unique_amount != '') {
    $form['uniqueamount'] = array(
      '#type' => 'textfield',
      '#title' => $unique_amount,
      '#size' => 15,
      '#field_suffix' => $currency,
    );
  }
  dsm(get_defined_vars());
  return $form;
}