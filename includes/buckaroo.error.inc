<?php
/**
 * Get all error message provided by buckaroo
 * @todo: make the messages trasnlatable
 * @return array
 */
function buckaroo_error_codes() {
  return array(
    0 => array(
      'status_code' => '0',
      'message' => t('The credit card transaction is pending.'),
      'error_level' => 'warning',
    ),
    1 => array(
      'status_code' => '1',
      'message' => t('The credit card transaction is pending. The MPI status of the customer is checked.'),
      'error_level' => 'warning',
    ),
    70 => array(
      'status_code' => '70',
      'message' => t('The refund is not processed.'),
      'error_level' => 'error',
    ),
    71 => array(
      'status_code' => '71',
      'message' => t('The refund has been processed successfully.'),
      'error_level' => 'success',
    ),
    72 => array(
      'status_code' => '72',
      'message' => t('There is an error in the refund.'),
      'error_level' => 'error',
    ),
    73 =>  array(
      'status_code' => '73',
      'message' => t('The credit has been canceled.'),
      'error_level' => 'error',
    ),
    74 => array (
      'status_code' => '74',
      'message' => t('Refund canceled. Insufficient funds.'),
      'error_level' => 'error',
    ),
    75 => array (
      'status_code' => '75',
      'message' => t('Refund failed. Invalid account numbers.'),
      'error_level' => 'error',
    ),
    76 => array (
      'status_code' => '76',
      'message' => t('The credit is refundable due to incorrect bank account details'),
      'error_level' => 'error',
    ),
    90 => array (
      'status_code' => '90',
      'message' => t('This transaction has not yet been fully processed.'),
      'error_level' => 'warning',
    ),
    91 => array (
      'status_code' => '91',
      'message' => t('This transaction was successfully processed.'),
      'error_level' => 'success',
    ),
    100 => array (
      'status_code' => '100',
      'message' => t('The transaction was approved by the credit company.'),
      'error_level' => 'success',
    ),
    101 => array(
      'status_code' => '101',
      'message' => t('The transaction is rejected by the credit company.'),
      'error_level' => 'error',
    ),
    102 => array(
      'status_code' => '102',
      'message' => t('The transaction failed. There is an error in processing the loan society.'),
      'error_level' => 'error',
    ),
    103 => array(
      'status_code' => '103',
      'message' => t('This credit card transaction is not executed within the maximum allowable time.'),
      'error_level' => 'error',
    ),
    104 => array(
      'status_code' => '104',
      'message' => t('The card has expired.'),
      'error_level' => 'error',
    ),
    105 => array(
      'status_code' => '105',
      'message' => t('Retrieval - Pending'),
      'error_level' => 'warning',
    ),
    106 => array(
      'status_code' => '106',
      'message' => t('Chargeback'),
      'error_level' => 'warning',
    ),
    120 => array(
      'status_code' => '120',
      'message' => t('This PayPal transaction has not been fully processed.'),
      'error_level' => 'warning',
    ),
    121 => array(
      'status_code' => '121',
      'message' => t('Transaction status: authorisation successful.'),
      'error_level' => 'success',
    ),
    122 => array(
      'status_code' => '122',
      'message' => t('This PayPal transaction is canceled by the consumer.'),
      'error_level' => 'error',
    ),
    123 => array(
      'status_code' => '123',
      'message' => t('This PayPal transaction is not within the maximum time allowed out.'),
      'error_level' => 'error',
    ),
    124 => array(
      'status_code' => '124',
      'message' => t('This PayPal transaction with PayPal for some reason failed.'),
      'error_level' => 'error',
    ),
    125 => array(
      'status_code' => '125',
      'message' => t('This PayPal transaction is not accepted.'),
      'error_level' => 'error',
    ),
    126 => array(
      'status_code' => '126',
      'message' => t('This PayPal transaction is pending.'),
      'error_level' => 'warning',
    ),
    135 => array(
      'status_code' => '135',
      'message' => t('This PayPal transaction has not been fully processed.'),
      'error_level' => 'warning',
    ),
    136 => array(
      'status_code' => '136',
      'message' => t('For technical reason the status of this transaction with PayPal is not exposed. The transaction may not yet finalized.'),
      'error_level' => 'warning',
    ),
    137 => array(
      'status_code' => '137',
      'message' => t('The depreciation code is invalid.'),
      'error_level' => 'error',
    ),
    138 => array(
      'status_code' => '138',
      'message' => t('There is a system error at PayPal. We apologize for the inconvenience.'),
      'error_level' => 'error',
    ),
    139 => array(
      'status_code' => '139',
      'message' => t('The PayPal transaction ID is invalid or unavailable.'),
      'error_level' => 'error',
    ),
    150 => array(
      'status_code' => '150',
      'message' => t('Paysafecard this transaction is not yet fully processed.'),
      'error_level' => 'warning',
    ),
    151 => array(
      'status_code' => '151',
      'message' => t('Transaction Status: authorization failed'),
      'error_level' => 'error',
    ),
    152 => array(
      'status_code' => '152',
      'message' => t('Paysafecard this transaction was canceled by the consumer.'),
      'error_level' => 'error',
    ),
    153 => array(
      'status_code' => '153',
      'message' => t('Paysafecard this transaction is within the maximum time allowed out.'),
      'error_level' => 'error',
    ),
    155 => array(
      'status_code' => '155',
      'message' => t('Paysafecard this transaction is not accepted.'),
      'error_level' => 'error',
    ),
    156 => array(
      'status_code' => '156',
      'message' => t('Paysafecard this transaction is not yet fully processed.'),
      'error_level' => 'warning',
    ),
    157 => array(
      'status_code' => '157',
      'message' => t('For technical reason the status of this transaction with Paysafecard not be traced. The transaction may not yet finalized.'),
      'error_level' => 'warning',
    ),
    158 => array(
      'status_code' => '158',
      'message' => t('There is a system error with Paysafecard. We apologize for the inconvenience.'),
      'error_level' => 'error',
    ),
    159 => array(
      'status_code' => '159',
      'message' => t('The paysafecard transaction ID is invalid or unavailable.'),
      'error_level' => 'error',
    ),
    170 => array(
      'status_code' => '170',
      'message' => 'These Cash-Ticket transaction is not yet fully processed.',
      'error_level' => 'warning',
    ),
    171 => array(
      'status_code' => '171',
      'message' => t('Transaction Status: authorization failed'),
      'error_level' => 'error',
    ),
    172 => array(
      'status_code' => '172',
      'message' => t('These Cash-Ticket transaction is canceled by the consumer.'),
      'error_level' => 'error',
    ),
    173 => array(
      'status_code' => '173',
      'message' => t('These Cash-Ticket transactions are not within the maximum time allowed out.'),
      'error_level' => 'error',
    ),
    175 => array(
      'status_code' => '175',
      'message' => t('These Cash-Ticket transactions are not accepted.'),
      'error_level' => 'error',
    ),
    176 => array(
      'status_code' => '176',
      'message' => t('These Cash-Ticket transaction is not yet fully processed.'),
      'error_level' => 'warning',
    ),
    177 => array(
      'status_code' => '177',
      'message' => t('For technical reason the status of this transaction are not with Cash-Ticket will be obsolete. The transaction may not yet finalized.'),
      'error_level' => 'warning',
    ),
    178 => array(
      'status_code' => '178',
      'message' => t('There is a system error occurred at Cash-Ticket. We apologize for the inconvenience.'),
      'error_level' => 'error',
    ),
    179 => array(
      'status_code' => '179',
      'message' => t('The Cash-Ticket transaction ID is invalid or unavailable.'),
      'error_level' => 'error',
    ),
    190 => array(
      'status_code' => '190',
      'message' => t('Success'),
      'error_level' => 'success',
    ),
    201 => array(
      'status_code' => '201',
      'message' => t('There is a timeout occurred while processing the transactie.Gebruik the TransactionKey to re-check the processing status.'),
      'error_level' => 'error',
    ),
    203 => array(
      'status_code' => '203',
      'message' => t('The transaction was declined. The credit card number is blocked.'),
      'error_level' => 'error',
    ),
    204 => array(
      'status_code' => '204',
      'message' => t('The transaction was declined. The IP address is blocked'),
      'error_level' => 'error',
    ),
    205 => array(
      'status_code' => '205',
      'message' => t('The transaction was declined. The country of issuance of this card is blocked'),
      'error_level' => 'error',
    ),
    206 => array(
      'status_code' => '206',
      'message' => t('The transaction was declined. The bill [value] is being or has been paid.'),
      'error_level' => 'error',
    ),
    207 => array(
      'status_code' => '207',
      'message' => t('The transaction was declined. The maximum number of attempts to pay bill [value] is exceeded.'),
      'error_level' => 'error',
    ),
    242 => array(
      'status_code' => '242',
      'message' => t('Commission payment processes guarantee a successful'),
      'error_level' => 'success',
    ),
    243 => array(
      'status_code' => '243',
      'message' =>  t('Fee collection agency guarantees payment successfully processed'),
      'error_level' => 'success',
    ),
    244 => array(
      'status_code' => '244',
      'message' => t('Buckaroo commission payment processes guarantee a successful'),
      'error_level' => 'success',
    ),
    245 => array(
      'status_code' => '245',
      'message' => t('Cost button collection agency guarantees payment successfully processed'),
      'error_level' => 'success',
    ),
    246 => array(
      'status_code' => '246',
      'message' => t('Tax collection agency guarantees payment successfully processed'),
      'error_level' => 'success',
    ),
    247 => array(
      'status_code' => '247',
      'message' => 'Buckaroo tax payment guarantee successful processing',
      'error_level' => 'success',
    ),
    251 => array(
      'status_code' => '251',
      'message' => 'Guarantee payment request is canceled',
      'error_level' => 'error',
    ),
    252 => array(
      'status_code' => '252',
      'message' => 'guarantee payment request rejected',
      'error_level' => 'error',
    ),
    253 => array(
      'status_code' => '253',
      'message' => 'guarantee payment request is not processed',
      'error_level' => 'error',
    ),
    254 => array(
      'status_code' => '254',
      'message' => 'guarantee payment request processed successfully',
      'error_level' => 'success',
    ),
    255 => array(
      'status_code' => '255',
      'message' => 'Credit note processed successfully',
      'error_level' => 'success',
    ),
    260 => array(
      'status_code' => '260',
      'message' => 'Credit control is not active subscription',
      'error_level' => 'error',
    ),
    261 => array(
      'status_code' => '261',
      'message' => 'Technical error occurred credit check',
      'error_level' => 'error',
    ),
    262 => array(
      'status_code' => '262',
      'message' => 'Required fields are missing or incorrect credit check',
      'error_level' => 'error',
    ),
    264 => array(
      'status_code' => '264',
      'message' => 'The payment guarantee payment is reversed.',
      'error_level' => 'error',
    ),
    300 => array(
      'status_code' => '300',
      'message' => 'Payment for this transfer is still awaited.',
      'error_level' => 'warning',
    ),
    301 => array(
      'status_code' => '301',
      'message' => 'The transfer was received.',
      'error_level' => 'success',
    ),
    302 => array(
      'status_code' => '302',
      'message' => 'The transaction is declined or rejected.',
      'error_level' => 'error',
    ),
    303 => array(
      'status_code' => '303',
      'message' => 'The due date for this transfer has expired.',
      'error_level' => 'error',
    ),
    304 => array(
      'status_code' => '304',
      'message' => 'The date of notice has expired.',
      'error_level' => 'error',
    ),
    305 => array(
      'status_code' => '305',
      'message' => 'The amount received for the transfer is less than the amount of the transaction.',
      'error_level' => 'error',
    ),
    306 => array(
      'status_code' => '306',
      'message' => 'The amount received for the transfer is greater than the amount of the transaction.',
      'error_level' => 'error',
    ),
    309 => array(
      'status_code' => '309',
      'message' => 'The transfer was canceled.',
      'error_level' => 'error',
    ),
    345 => array(
      'status_code' => '345',
      'message' => 'Original transaction amount divided; new transactions created.',
      'error_level' => 'error',
    ),
    372 => array(
      'status_code' => '372',
      'message' => 'Crediting external account.',
      'error_level' => 'success',
    ),
    390 => array(
      'status_code' => '390',
      'message' => 'The transaction is outside Buckaroo dealt with the client.',
      'error_level' => 'error',
    ),
    392 => array(
      'status_code' => '392',
      'message' => 'Otherwise paid',
      'error_level' => 'error',
    ),
    400 => array(
      'status_code' => '400',
      'message' => 'The gift card transaction is still pending',
      'error_level' => 'warning',
    ),
    401 => array(
      'status_code' => '401',
      'message' => 'The payment by successful gift card.',
      'error_level' => 'success',
    ),
    402 => array(
      'status_code' => '402',
      'message' => 'Payment by the gift card was rejected.',
      'error_level' => 'error',
    ),
    409 => array(
      'status_code' => '409',
      'message' => 'Payment by the gift card is canceled.',
      'error_level' => 'error',
    ),
    410 => array(
      'status_code' => '410',
      'message' => 'The Merchant Account Code is invalid',
      'error_level' => 'error',
    ),
    411 => array(
      'status_code' => '411',
      'message' => 'Payment by card kad tentatively accepted.',
      'error_level' => 'success',
    ),
    414 => array(
      'status_code' => '414',
      'message' => 'A system error has occurred.',
      'error_level' => 'error',
    ),
    421 => array(
      'status_code' => '421',
      'message' => 'An unknown Issuer for the gift card given.',
      'error_level' => 'error',
    ),
    422 => array(
      'status_code' => '422',
      'message' => 'There is an error in the Issuer. The payment has failed. [Value].',
      'error_level' => 'error',
    ),
    425 => array(
      'status_code' => '425',
      'message' => 'Not enough funds to carry out this transaction.',
      'error_level' => 'error',
    ),
    460 => array(
      'status_code' => '460',
      'message' => 'Pending',
      'error_level' => 'warning',
    ),
    461 => array(
      'status_code' => '461',
      'message' => 'Transaction completed',
      'error_level' => 'success',
    ),
    462 => array(
      'status_code' => '462',
      'message' => 'Transaction completed',
      'error_level' => 'success',
    ),
    463 => array(
      'status_code' => '463',
      'message' => 'Transaction completed',
      'error_level' => 'success',
    ),
    464 => array(
      'status_code' => '464',
      'message' => 'Transaction completed',
      'error_level' => 'success',
    ),
    466 => array(
      'status_code' => '466',
      'message' => 'Rejected by the collection agency:',
      'error_level' => 'error',
    ),
    468 => array(
      'status_code' => '468',
      'message' => 'Original invoice for the application is not found',
      'error_level' => 'error',
    ),
    490 => array(
      'status_code' => '490',
      'message' => 'Failed',
      'error_level' => 'error',
    ),
    491 => array(
      'status_code' => '491',
      'message' => 'Validation Error',
      'error_level' => 'error',
    ),
    492 => array(
      'status_code' => '492',
      'message' => 'Technical fault',
      'error_level' => 'error',
    ),
    500 => array(
      'status_code' => '500',
      'message' => 'Paypermail: transaction pending',
      'error_level' => 'warning',
    ),
    501 => array(
      'status_code' => '501',
      'message' => 'Online transaction processing transfer',
      'error_level' => 'warning',
    ),
    541 => array(
      'status_code' => '541',
      'message' => 'Transaction costs are deducted from net',
      'error_level' => 'warning',
    ),
    550 => array(
      'status_code' => '550',
      'message' => 'The payout has not been processed.',
      'error_level' => 'error',
    ),
    551 => array(
      'status_code' => '551',
      'message' => 'The payment is successfully processed.',
      'error_level' => 'success',
    ),
    552 => array(
      'status_code' => '552',
      'message' => 'The payout has been canceled.',
      'error_level' => 'error',
    ),
    553 => array(
      'status_code' => '553',
      'message' => 'The payment has failed.',
      'error_level' => 'error',
    ),
    554 => array(
      'status_code' => '554',
      'message' => 'Payment canceled. Insufficient funds.',
      'error_level' => 'error',
    ),
    555 => array(
      'status_code' => '555',
      'message' => 'Payment failed. Invalid account numbers.',
      'error_level' => 'error',
    ),
    556 => array(
      'status_code' => '556',
      'message' => 'The payment is refunded by the bank due to incorrect account information',
      'error_level' => 'error',
    ),
    560 => array(
      'status_code' => '560',
      'message' => 'Payment adjustment performed by Buckaroo.',
      'error_level' => 'success',
    ),
    581 => array(
      'status_code' => '581',
      'message' => 'Transfer to or from another account Buck',
      'error_level' => 'success',
    ),
    590 => array(
      'status_code' => '590',
      'message' => 'The partner fee is processed.',
      'error_level' => 'success',
    ),
    600 => array(
      'status_code' => '600',
      'message' => 'Debit has not been processed.',
      'error_level' => 'error',
    ),
    601 => array(
      'status_code' => '601',
      'message' => 'Debit has been successfully processed.',
      'error_level' => 'success',
    ),
    602 => array(
      'status_code' => '602',
      'message' => 'Debit is rejected by the bank.',
      'errr_level' => 'error',
    ),
    605 => array(
      'status_code' => '605',
      'message' => 'Debit is reversed.',
      'error_level' => 'error',
    ),
    609 => array(
      'status_code' => '609',
      'message' => 'Debit is canceled before collection occurred.',
      'error_level' => 'error',
    ),
    610 => array(
      'status_code' => '610',
      'message' => 'Debit is rejected by the bank. Invalid account.',
      'error_level' => 'error',
    ),
    612 => array(
      'status_code' => '612',
      'message' => 'Reversal due Reporting Incorrect Collection',
      'error_level' => 'error',
    ),
    690 => array(
      'status_code' => '690',
      'message' => 'Rejected',
      'error_level' => 'error',
    ),
    700 => array(
      'status_code' => '700',
      'message' => 'The payment order is accepted and processed.',
      'error_level' => 'success',
    ),
    701 => array(
      'status_code' => '701',
      'message' => 'The payment order is processed.',
      'error_level' => 'success',
    ),
    702 => array(
      'status_code' => '702',
      'message' => 'The payment order is returned due to incorrect bank account details',
      'error_level' => 'error',
    ),
    703 => array(
      'status_code' => '703',
      'message' => 'The payment order is rejected by Buckaroo.',
      'error_level' => 'error',
    ),
    704 => array(
      'status_code' => '704',
      'message' => 'Payment Order canceled',
      'error_level' => 'error',
    ),
    705 => array(
      'status_code' => '705',
      'message' => 'The batch could not be scheduled. Error: [value]',
      'error_level' => 'error',
    ),
    706 => array(
      'status_code' => '706',
      'message' => 'Payment Operation failed. Invalid account numbers.',
      'error_level' => 'error',
    ),
    707 => array(
      'status_code' => '707',
      'message' => 'Pay Job canceled. Insufficient funds.',
      'error_level' => 'error',
    ),
    708 => array(
      'status_code' => '708',
      'message' => 'The payment order is returned due to incorrect bank account details',
      'error_level' => 'error',
    ),
    710 => array(
      'status_code' => '710',
      'message' => 'Payment Order not be confirmed.',
      'error_level' => 'error',
    ),
    711 => array(
      'status_code' => '711',
      'message' => 'The batch could not be found: [value].',
      'error_level' => 'error',
    ),
    712 => array(
      'status_code' => '712',
      'message' => 'The batch has been processed: [value].',
      'error_level' => 'success',
    ),
    720 => array(
      'status_code' => '720',
      'message' => 'There is no transaction for this batch client ID specified.',
      'error_level' => 'error',
    ),
    721 => array(
      'status_code' => '721',
      'message' => 'The specified client ID could not be found: [value].',
      'error_level' => 'error',
    ),
    790 => array(
      'status_code' => '790',
      'message' => 'Pending input',
      'error_level' => 'warning',
    ),
    791 => array(
      'status_code' => '791',
      'message' => 'Pending Processing',
      'error_level' => 'warning',
    ),
    800 => array(
      'status_code' => '800',
      'message' => 'This PayPal transaction has not yet been fully processed.',
      'error_level' => 'warning',
    ),
    801 => array(
      'status_code' => '801',
      'message' => 'This iDEAL transaction has been successfully processed.',
      'error_level' => 'success',
    ),
    802 => array(
      'status_code' => '802',
      'message' => 'This iDEAL transaction has been canceled by the consumer. Trx: [value]',
      'error_level' => 'error',
    ),
    803 => array(
      'status_code' => '803',
      'message' => 'This iDEAL transaction is not within the maximum time allowed out. Trx: [value]',
      'error_level' => 'error',
    ),
    804 => array(
      'status_code' => '804',
      'message' => 'This iDEAL transaction for some reason the bank failed. Trx: [value]',
      'error_level' => 'error',
    ),
    810 => array(
      'status_code' => '810',
      'message' => 'Issuer (bank) is unknown: [value]',
      'error_level' => 'error',
    ),
    811 => array(
      'status_code' => '811',
      'message' => 'For technical reason the status of this transaction at the bank are not yet obsolete. The transaction is still ongoing.',
      'error_level' => 'warning',
    ),
    812 => array(
      'status_code' => '812',
      'message' => 'The entrance code [value] is invalid.',
      'error_level' => 'error',
    ),
    813 => array(
      'status_code' => '813',
      'message' => 'Acquirer code is unknown: [value].',
      'error_level' => 'error',
    ),
    814 => array(
      'status_code' => '814',
      'message' => 'There is a system error. We will resolve this as quickly as possible. The status will then be reviewed.',
      'error_level' => 'warning',
    ),
    815 => array(
      'status_code' => '815',
      'message' => '" At present',
      'error_level' => ' the iDEAL payment not available due to a malfunction in the bank"',
    ),
    816 => array(
      'status_code' => '816',
      'message' => 'There was no transaction to be found. Criteria: [value]',
      'error_level' => 'error',
    ),
    820 => array(
      'status_code' => '820',
      'message' => 'Giropay this transaction is not yet fully processed.',
      'error_level' => 'warning',
    ),
    821 => array(
      'status_code' => '821',
      'message' => 'Giropay this transaction was successfully processed.',
      'error_level' => 'success',
    ),
    822 => array(
      'status_code' => '822',
      'message' => 'Giropay this transaction was canceled by the consumer. Trx: [value]',
      'error_level' => 'error',
    ),
    823 => array(
      'status_code' => '823',
      'message' => 'Giropay this transaction is within the maximum time allowed out. Trx: [value]',
      'error_level' => 'error',
    ),
    824 => array(
      'status_code' => '824',
      'message' => 'Giropay this transaction was rejected by the bank.',
      'error_level' => 'error',
    ),
    830 => array(
      'status_code' => '830',
      'message' => 'Issuer (bankleitzahl) is unknown: [value]',
      'error_level' => 'error',
    ),
    831 => array(
      'status_code' => '831',
      'message' => 'For technical reason the status of this transaction at the bank are not yet obsolete. The transaction is still ongoing.',
      'error_level' => 'warning',
    ),
    833 => array(
      'status_code' => '833',
      'message' => 'The entrance code [value] is invalid.',
      'error_level' => 'error',
    ),
    834 => array(
      'status_code' => '834',
      'message' => 'There is a system error. We will resolve this as quickly as possible. The status will then be reviewed.',
      'error_level' => 'warning',
    ),
    835 => array(
      'status_code' => '835',
      'message' => 'Giropay The transaction ID is invalid or unavailable.',
      'error_level' => 'error',
    ),
    836 => array(
      'status_code' => '836',
      'message' => 'There was no transaction to be found. Criteria: [value]',
      'error_level' => 'error',
    ),
    890 => array(
      'status_code' => '890',
      'message' => 'Cancelled by Consumer',
      'error_level' => 'error',
    ),
    891 => array(
      'status_code' => '891',
      'message' => 'Cancelled by Merchant',
      'error_level' => 'error',
    ),
    900 => array(
      'status_code' => '900',
      'message' => 'No XML message.',
      'error_level' => 'error',
    ),
    901 => array(
      'status_code' => '901',
      'message' => 'Invalid XML message. [Value]',
      'error_level' => 'error',
    ),
    910 => array(
      'status_code' => '910',
      'message' => '" 0 EUR transactions',
      'error_level' => ' customer information is stored."',
    ),
    931 => array(
      'status_code' => '931',
      'message' => '[NodeType] [element] is missing.',
      'error_level' => 'error',
    ),
    932 => array(
      'status_code' => '932',
      'message' => 'Too many elements type [element] (max. 1).',
      'error_level' => 'error',
    ),
    933 => array(
      'status_code' => '933',
      'message' => 'Value [NodeType] [element] is missing.',
      'error_level' => 'error',
    ),
    934 => array(
      'status_code' => '934',
      'message' => 'Value [NodeType] [element] (occurance [occurance]) is missing.',
      'error_level' => 'error',
    ),
    935 => array(
      'status_code' => '935',
      'message' => 'Value attribute [attribute] missing element [element].',
      'error_level' => 'error',
    ),
    940 => array(
      'status_code' => '940',
      'message' => 'Invalid request: [value].',
      'error_level' => 'error',
    ),
    941 => array(
      'status_code' => '941',
      'message' => 'Value field [field] void [value].',
      'error_level' => 'error',
    ),
    942 => array(
      'status_code' => '942',
      'message' => 'Attribute value [field] void [value].',
      'error_level' => 'error',
    ),
    943 => array(
      'status_code' => '943',
      'message' => 'Credit card type is unknown: [value]. (MasterCard or Visa)',
      'error_level' => 'error',
    ),
    944 => array(
      'status_code' => '944',
      'message' => 'Invalid card number (Luhn check): [value].',
      'error_level' => 'error',
    ),
    945 => array(
      'status_code' => '945',
      'message' => 'Unknown value is invalid: [value].',
      'error_level' => 'error',
    ),
    946 => array(
      'status_code' => '946',
      'message' => 'Amount is not a numeric value: [value].',
      'error_level' => 'error',
    ),
    947 => array(
      'status_code' => '947',
      'message' => 'Amount invalid: [value].',
      'error_level' => 'error',
    ),
    948 => array(
      'status_code' => '948',
      'message' => 'CVC is invalid: [value].',
      'error_level' => 'error',
    ),
    949 => array(
      'status_code' => '949',
      'message' => 'Month valid credit card is invalid: [value].',
      'error_level' => 'error',
    ),
    950 => array(
      'status_code' => '950',
      'message' => 'Year credit period is invalid: [value].',
      'error_level' => 'error',
    ),
    951 => array(
      'status_code' => '951',
      'message' => 'Language unknown or unsupported: [value].',
      'error_level' => 'error',
    ),
    952 => array(
      'status_code' => '952',
      'message' => 'The invoice number is missing. This field is required.',
      'error_level' => 'error',
    ),
    953 => array(
      'status_code' => '953',
      'message' => 'Blocked by velocity check',
      'error_level' => 'error',
    ),
    954 => array(
      'status_code' => '954',
      'message' => 'The transaction ID [value] is already in use.',
      'error_level' => 'error',
    ),
    955 => array(
      'status_code' => '955',
      'message' => 'Authentication for this credit card payment is rejected',
      'error_level' => 'error',
    ),
    956 => array(
      'status_code' => '956',
      'message' => 'The enrolled status of the card could not be traced.',
      'error_level' => 'error',
    ),
    960 => array(
      'status_code' => '960',
      'message' => 'Customer number is invalid: [value].',
      'error_level' => 'error',
    ),
    961 => array(
      'status_code' => '961',
      'message' => 'Credit card type not activated [value].',
      'error_level' => 'error',
    ),
    962 => array(
      'status_code' => '962',
      'message' => 'Selected currency invalid for Merchant: [value].',
      'error_level' => 'error',
    ),
    963 => array(
      'status_code' => '963',
      'message' => 'The transaction ID is invalid: [value]',
      'error_level' => 'error',
    ),
    964 => array(
      'status_code' => '964',
      'message' => 'There are no payment methods enabled.',
      'error_level' => 'error',
    ),
    971 => array(
      'status_code' => '971',
      'message' => 'There is no name specified.',
      'error_level' => 'error',
    ),
    972 => array(
      'status_code' => '972',
      'message' => 'There is no address entered.',
      'error_level' => 'error',
    ),
    973 => array(
      'status_code' => '973',
      'message' => 'There is no zip code entered.',
      'error_level' => 'error',
    ),
    974 => array(
      'status_code' => '974',
      'message' => 'There is no place filled.',
      'error_level' => 'error',
    ),
    975 => array(
      'status_code' => '975',
      'message' => 'No country entered.',
      'error_level' => 'error',
    ),
    976 => array(
      'status_code' => '976',
      'message' => 'There is no gender entered.',
      'error_level' => 'error',
    ),
    977 => array(
      'status_code' => '977',
      'message' => 'Address is invalid',
      'error_level' => 'error',
    ),
    978 => array(
      'status_code' => '978',
      'message' => 'The XML link for credit cards is not yet activated.',
      'error_level' => 'error',
    ),
    980 => array(
      'status_code' => '980',
      'message' => 'The payment [value] is not activated.',
      'error_level' => 'error',
    ),
    981 => array(
      'status_code' => '981',
      'message' => 'The date of the subscription is not a valid date.',
      'error_level' => 'error',
    ),
    982 => array(
      'status_code' => '982',
      'message' => 'The subscription has not yet begun.',
      'error_level' => 'error',
    ),
    983 => array(
      'status_code' => '983',
      'message' => 'The subscription has expired.',
      'error_level' => 'error',
    ),
    990 => array(
      'status_code' => '990',
      'message' => 'The digital signature is incorrect: [value].',
      'error_level' => 'error',
    ),
    991 => array(
      'status_code' => '991',
      'message' => 'There is an error occurred while processing the transaction. The Merchant Account Code could not be located.',
      'error_level' => 'error',
    ),
    992 => array(
      'status_code' => '992',
      'message' => 'There is error while processing the response. We will fix the problem as quickly as possible.',
      'error_level' => 'error',
    ),
    993 => array(
      'status_code' => '993',
      'message' => 'There is an error occurred while processing the transaction.',
      'error_level' => 'error',
    ),
    999 => array(
      'status_code' => '999',
      'message' => 'There is an error whose cause is still unknown. We will fix the problem as quickly as possible.',
      'error_level' => 'error',
    ),
  );
}

/**
 * Helper function to read statuscodes.csv.
 * Only for development usage.
 * @return array
 */
function _buckaroo_get_error_codes() {
  global $base_url;
  $file = drupal_get_path('module', 'buckaroo') . '/statuscodes.csv';

  $header = array('status_code', 'message', 'error_level');;
  $data = array();
  $csvData = str_getcsv(file_get_contents($file), "\n");

  foreach ($csvData as $csvLine) {
      $items = explode(',', $csvLine);
      for ($n = 0, $m = count($header); $n < $m; $n++) {
        $prepareData[$header[$n]] = $items[$n];
      }
      $data[$prepareData['status_code']] = $prepareData;
  }

  return $data;
}
