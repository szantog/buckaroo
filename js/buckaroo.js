/**
 *  @file
 *  Set hidden values in donate forms
 */
var Buckaroo = {};


(function ($) {
  var BuckarooForm = $('#buckaroo-payment-form');
  var BuckarooContext = '#buckaroo-payment-form'
  var WrongKey = false;


  Drupal.behaviors.buckaroo = {
    attach: function (context, settings) {

      var BPE_Amount = $('input[name=BPE_Amount]');

      BPE_Amount.val($('#edit-amount :radio:first', BuckarooContext).val() * 100);

      // Remove checked, if uniqueamont field get focus.
      $('#edit-uniqueamount', BuckarooContext).focus (function () {
        $('#edit-amount :radio', BuckarooContext).attr('checked', false);
      })

      // If no unique amount value, make the first radio checked.
      // else set the BPE_value
      $('#edit-uniqueamount', BuckarooContext).blur (function () {
        if ($(this).val == '') {
          $('#edit-amount :radio:first', BuckarooContext).attr('checked', true);
        }
        else {
          BPE_Amount.val($(this).val() * 100);
        }
      })

      // If a radio is clicked, remove the uniqeamount value, and set BPE_value
      $('#edit-amount :radio', BuckarooContext).click (function () {
        $('#edit-uniqueamount', BuckarooContext).val('');
        ammount = $(this).val();
        BPE_Amount.val($(this).val() * 100);
      })

      // Disable the non-numeric characters.
      $('#edit-uniqueamount', BuckarooContext).keydown(function(event) {
        var msg = $('<div class="clear error">' + Drupal.t('Only numbers are allowed.') + '</div>');
        // Allow only backspace and delete and tab
        if (event.keyCode == 46 || event.keyCode == 8 || event.keyCode == 9) {
          WrongKey = false;
        }
        else {
            // Ensure that it is a number and stop the keypress
          if ((event.keyCode < 48 || event.keyCode > 57) && (event.keyCode < 96 || event.keyCode > 105 )) {
            var parent = $(this).parents(".form-item");
            if (WrongKey == false) {
              msg.hide();
              $(parent).append(msg);
              WrongKey = true;
              msg.fadeIn();
            }
            event.preventDefault();
          }
        }
      });

      // Basic form validation, and pass values to hidden elements. If something
      // wrong, the normal validate process continue via drupal.
      $("#buckaroo-payment-form .form-submit", context).click(function(e) {
        var name = $(this).attr('name');
        eval('var FormAction = settings.Buckaroo.' + name + '.action;');

        if (Buckaroo.valid()) {
          //BuckarooForm.Prepare();
          $('#buckaroo-payment-form').attr("action", FormAction);
          //e.preventDefault();
        }
        else {
          e.preventDefault();
        }
      })

      BuckarooForm.Prepare = function() {
        $('input[type!="hidden"]', BuckarooContext).each(function(){
          var html = $('<input type="hidden" value="' + $(this).val() + '" name="' + $(this).attr('name') + '">');
          $('#buckaroo-payment-form div:first').prepend(html);
        });
      }
    }
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
  }

//  Buckaroo.error = function(id) {
//    var parent = $(id).parents(".form-item");
//    var label = $("label:not(label>span)", parent).text();
//    $(parent).append('<div class="error">' + Drupal.t(label + 'field is required.') + '</div>');
//    $(parent).show();
//    return;
//  }

}(jQuery));