<?php

/**
 * @file
 * Settings for Buckaroo payment page.
 */

/**
 * Implementation of hook_rules_event_info().
 */
function buckaroo_rules_event_info() {
  $defaults = array(
    'group' => t('Buckaroo'),
    'module' => 'buckaroo',
    'variables' => array(
      'result' => array(
        'type' => 'buckaroo_result',
        'label' => t('The result of the buckaroo payment'),
      ),
    ),
    //'access callback' => 'rules_comment_integration_access',
  );
  return array(
    'buckaroo_success' => $defaults + array(
      'label' => t('After succesful payment'),
    ),
    'buckaroo_error' => $defaults + array(
      'label' => t('After unsuccesful payment'),
    ),
  );
}

function buckaroo_rules_data_info() {
  return array(
    'buckaroo_result' => array(
      'label' => t('Payment result'),
      'group' => t('Buckaroo'),
    ),
  );
}