<?php

/**
 * @file
 * Settings for Buckaroo payment page.
 */

function buckaroo_admin_form($form_state) {
  $form = array();
  $vars = buckaroo_variable_get();

  $form['buckaroo_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path'),
    '#default_value' => $vars['path'],
    '#size' => 40,
    '#description' => t('Specify a relative URL to show Buckaroo payment form. Use "node/[nid]" path, if you want to attach form to a node.'),
    '#field_prefix' => url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
    '#required' => TRUE,
  );
  $form['amount'] = array(
    '#type' => 'fieldset',
    '#title' => t('Ammount selection settings'),
  );
  $form['amount']['buckaroo_amount_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title of amount selection section'),
    '#default_value' => $vars['amount_title'],
    '#size' => 60,
    '#description' => t('Specify a the title of amount selection section.'),
  );
  $form['amount']['buckaroo_amount_values'] = array(
    '#title' => t('Amount values'),
    '#type' => 'textarea',
    '#description' => t('Need some text'),
    '#default_value' => drupal_implode_tags($vars['amount_values']),
  );
  $form['amount']['buckaroo_amount_curr'] = array(
    '#type' => 'textfield',
    '#title' => t('Currency'),
    '#default_value' => $vars['currency'],
    '#size' => 5,
  );
  $form['amount']['buckaroo_unique_amount'] = array(
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
    $form['method']["buckaroo_{$key}_enabled"] = array(
      '#type' => 'checkbox',
      '#title' => t($value['name']),
      '#default_value' => $value['enabled'],
    );
  }

  $form['buckaroo_test'] = array(
    '#type' => 'checkbox',
    '#title' => t('Test'),
    '#default_value' => $vars['test'],
    '#description' => t('Using Buckaroo payment gateway as test mode. WARNING! No valid transactions ... need text'),
  );

  return system_settings_form($form);
}

function buckaroo_admin_form_validate($form, &$form_state) {
  $form_state['values']['buckaroo_amount_values'] = drupal_explode_tags($form_state['values']['buckaroo_amount_values']);
}

function buckaroo_admin_form_submit($form, &$form_state) {
  //Rebuild menu, if path changed.
  if ($form['buckaroo_path']['#default_value'] != $form_state['values']['buckaroo_path']) {
    menu_rebuild();
  }
}