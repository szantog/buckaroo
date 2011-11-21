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
//  $form = array(
//    '#action' => 'https://payment.buckaroo.nl/gateway/paypal_payment.asp',
//
//    'submit' => array(
//      '#type' => 'submit',
//      '#value' => t('Paypal'),
//      '#attributes' => array(
//        'id' => 'pp_submit'
//      )
//    ),
//  );
  //$form += buckaroo_get_hidden_elements('pp');
  return $form;
}

function buckaroo_pp_form($form_state) {
  $form = array(
    '#action' => 'https://payment.buckaroo.nl/gateway/paypal_payment.asp',

    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Paypal'),
      '#attributes' => array(
        'id' => 'pp_submit'
      )
    ),
  );
  $form += buckaroo_get_hidden_elements('pp');
  return $form;
}

function buckaroo_ideal_form($form_state) {
  $form = array(
    '#action' => 'https://payment.buckaroo.nl/gateway/ideal_payment.asp',

    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Ideal'),
      '#attributes' => array(
        'id' => 'pp_submit'
      )
    ),
  );
  $form += buckaroo_get_hidden_elements('pp');
  return $form;
}

function buckaroo_get_hidden_elements($machine_name) {
  $vars = buckaroo_variable_get();
  //Look at BPE_Return_Method
  $need_post_method = array('pp', 'ideal');
  $return = array();

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
    'BPE_Issuer' => array(
      '#type' => 'hidden',
      '#value' => '',
      'used' => array (
        'ideal'
      )
    ),
    //short transaction description.
    'BPE_Description' => array(
      '#type' => 'hidden',
      '#value' => 'need something..',
      'used' => array (
        'pp'
      )
    ),
    //Language code for the user interface language:NL = Dutch EN = English;
    'BPE_Language' => array(
      '#type' => 'hidden',
      '#value' => 'EN',
      'used' => array (
        'pp'
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
        'pp'
      )
    ),
    //Specify a different URL for the return page for successful payments.
    'BPE_Return_Success' => array(
      '#type' => 'hidden',
      '#value' => '',
      'used' => array (
        'all'
      )
    ),
    //Specify a different URL for the return page for payments rejected by PayPal (processor).
    'BPE_Return_Reject' => array(
      '#type' => 'hidden',
      '#value' => '',
      'used' => array (
        'all'
      )
    ),
    //Specify a different URL for the return page for payments that cannot be processed due to a technical malfunction.
    'BPE_Return_Error' => array(
      '#type' => 'hidden',
      '#value' => '',
      'used' => array (
        'all'
      )
    ),
    //Specify how result parameters should be passed to your response pages:
    'BPE_Return_Method' => array(
      '#type' => 'hidden',
      '#value' => in_array($machine_name, $need_post_method) ? 'POST' : 'GET',
      'used' => array (
        'pp'
      )
    ),
  );
  foreach ($elements as $key => $element) {
    if (in_array($machine_name, $element['used']) || in_array('all', $element['used'])) {
      unset($element['used']);
      $return[$key] = $element;
    }
  }
  return $return;
}