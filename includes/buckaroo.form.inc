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
  $vars = buckaroo_variable_get();

  foreach ($vars['amount_values'] as $value) {
    $values[$value] = $value . ' ' . $vars['currency'];
  }
  $form['amount'] = array(
    '#type' => 'radios',
    '#default_value' => isset($_GET['default_amount']) ? $_GET['default_amount'] : $vars['amount_values'][0],
    '#options' => $values,
  );

  if ($vars['unique_amount'] != '') {
    $form['uniqueamount'] = array(
      '#type' => 'textfield',
      '#title' => $vars['unique_amount'],
      '#size' => 15,
      '#field_suffix' => $vars['currency'],
    );
  }
  return $form;
}

function buckaroo_cc_form($form_state) {
  $form = array();
  return $form;
}

function buckaroo_pp_form($form_state) {
  $form = array();
  return $form;
}