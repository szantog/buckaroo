/**
 *  @file
 *  Set hidden values in donate forms
 */
var Buckaroo = {};


(function ($) {
  var BuckarooForm = $('#buckaroo-payment-form');
  var BuckarooContext = '#buckaroo-payment-form'
  var WrongKey = false;
  var ErrorSent = {};


  Drupal.behaviors.buckaroo = {
    attach: function (context, settings) {

      var BPE_Amount = $('input[name=BPE_Amount]');
      // The amount of payment transfer to Buckaroo
      var amount = $('#edit-amount :radio:first', BuckarooContext).val();

      // Get new signature value based on new amount
      Buckaroo.GetSignature = function() {
        var url = '/buckaroo/get-signature?BPE_Amount=' + amount + '&BPE_Invoice=' + $('input[name=BPE_Invoice]', context).val();
        var params = {format: 'json'};
        var data = null;

        $.ajax({
          url: '/buckaroo/get-signature?BPE_Amount=' + amount + '&BPE_Invoice=' + $('input[name=BPE_Invoice]', context).val(),
          async: false,
          data: {BPE_Amount: amount, BPE_Invoice: $('input[name=BPE_Invoice]', context).val()},
          dataType: 'json',
          success: function (json) {
            data = json;
            data = json;
          }
        });
        return data;
      };

      Buckaroo.valid = function() {
        var error = false;
        $("#buckaroo-payment-form .required").each(function() {
          if ($(this).val() == '') {
            error = true;
          }
        });
        if (!error) {
          return true;
        }
      };

      Buckaroo.error = function(text, from) {
        var parent = $(from).parents(".form-item");
        var msg = $('<div class="clear error">' + Drupal.t(text) + '</div>');

        if (ErrorSent[text] != true) {
          msg.hide();
          $(parent).append(msg);
          ErrorSent[text] = true;
          //debugger;
          msg.fadeIn();
        };

      };

      // Remove checked, if uniqueamont field get focus.
      $('#edit-uniqueamount', BuckarooContext).focus (function () {
        $('#edit-amount :radio', BuckarooContext).attr('checked', false);
      })

      // If no unique amount value, make the first radio checked.
      // else set the BPE_value
      $('#edit-uniqueamount', BuckarooContext).blur (function () {
        if ($(this).val() == '') {
          $('#edit-amount :radio:first', BuckarooContext).attr('checked', true);
        }
        else {
          amount = $(this).val();
        }
      })

      // If a radio is clicked, remove the uniqeamount value, and set BPE_value
      $('#edit-amount :radio', BuckarooContext).click (function () {
        $('#edit-uniqueamount', BuckarooContext).val('');
        amount = $(this).val();
      })

      // Disable the non-numeric characters.
      $('#edit-uniqueamount', BuckarooContext).keydown(function(event) {
        // Allow only backspace and delete and tab
        if (event.keyCode == 46 || event.keyCode == 8 || event.keyCode == 9) {
          return;
        }
          // Ensure that it is a number and stop the keypress
        if ((event.keyCode < 48 || event.keyCode > 57) && (event.keyCode < 96 || event.keyCode > 105 )) {
          Buckaroo.error('Only numbers are allowed.', $(this).get());
          event.preventDefault();
        }
      });

      // Basic form validation, and pass values to hidden elements. If something
      // wrong, the normal validate process continue via drupal.
      $("#buckaroo-payment-form .form-submit", context).click(function(e) {
        var name = $(this).attr('name');
        eval('var FormAction = settings.Buckaroo.' + name + '.action;');

        if (Buckaroo.valid()) {
          BPE_Amount.val(amount * 100);
          var sign = Buckaroo.GetSignature();
          $('input[name=BPE_Signature2]', context).val(sign);
          $('#buckaroo-payment-form').attr("action", FormAction);
          //e.preventDefault();
        }

        else {
          e.preventDefault();
        }
      })
    }
  };
}(jQuery));