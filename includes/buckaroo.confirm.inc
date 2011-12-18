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
    '#markup' => $_GET['value'],
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
      '#value' => $_GET['value'] * 100,
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
      '#value' => url($vars['success_path'], array('absolute' => TRUE)),
      'used' => array (
        'all'
      )
    ),
    //Specify a different URL for the return page for payments rejected by PayPal (processor).
    'BPE_Return_Reject' => array(
      '#type' => 'hidden',
      '#value' => url($vars['error_path'], array('absolute' => TRUE)),
      'used' => array (
        'all'
      )
    ),
    //Specify a different URL for the return page for payments that cannot be processed due to a technical malfunction.
    'BPE_Return_Error' => array(
      '#type' => 'hidden',
      '#value' => url($vars['error_path'], array('absolute' => TRUE)),
      'used' => array (
        'all'
      )
    ),
    //Specify how result parameters should be passed to your response pages:
    'BPE_Return_Method' => array(
      '#type' => 'hidden',
      '#value' => in_array($machine_name, $need_post_method) ? 'POST' : 'GET',
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
  //dsm(get_defined_vars());
  return $return;
}

