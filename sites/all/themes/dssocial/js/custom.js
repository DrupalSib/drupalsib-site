var $embed = new Array();
var firstshow = 1;
var I20DS = I20DS || {};
I20DS.maxSize = 2097152;
I20DS.formatFileSize = function(size) {
  var unit = '';
  size = size / 1024;
  if (size / 1024 > 1) {
    if ((size / 1048576) > 1) {
      size = (Math.round((size / 1048576) * 100) / 100);
      unit = "Gb";
    }
    else {
      size = (Math.round((size / 1024) * 100) / 100)
      unit = "Mb";
    }
  }
  else {
    size = (Math.round(size * 100) / 100)
    unit = "Kb";
  }
  return size + ' ' + unit;
};

(function ($, Drupal, window, document) {

  Drupal.behaviors.drupalSibCore = {
    attach: function(context, settings) {
      // Slider viewer
      var totalslide = $('#deck-container > div').size();

      $('#deck-container').cycle({
        fx: 'fade',
        speed: 1000,
        next: '.deck-next-link',
        prev: '.deck-prev-link',
        before: stopVideo,
        onPrevNextEvent: changeIcon
      });
      $('#deck-container').cycle('pause');
      $('#currSlide').html('1');
      $('#totalSlide').html(totalslide);
    }
  }

  function stopVideo(currSlideElement, nextSlideElement, options, forwardFlag) {
    var list_slide_deck = $('#deck-container > div');
    if (firstshow != 1) {
      $embed[$(currSlideElement).attr('id')] = $(currSlideElement).find('.media').html();
      // $(currSlideElement).find('.media').html("");
      if ($embed[$(nextSlideElement).attr('id')]) $(nextSlideElement).find('.media').html($embed[$(nextSlideElement).attr('id')]);
      $('#currSlide').html(list_slide_deck.index($(nextSlideElement)) + 1);
    } else {
      firstshow = 0;
    }
  }

  function changeIcon(index, el, item) {
    if ($('#viewer-nav-bottom .jcarousel-item-' + (el + 1) + ':not(.active)').html()) {
      $('#viewer-nav-bottom').find('.jcarousel-item.active').fadeTo("fast", 0.4);
      $('#viewer-nav-bottom').find('.jcarousel-item.active').removeClass("active");
      $('#viewer-nav-bottom .jcarousel-item-' + (el + 1)).fadeTo("fast", 1);
      $('#viewer-nav-bottom .jcarousel-item-' + (el + 1)).addClass("active");
    }
  }

  Drupal.behaviors.drupalSibFile = {
    attach: function(context, settings) {
      console.log('it change');
      $("#edit-profile-main-profile-field-logo-und-0-upload").not('.drupalsib-file-processed').addClass('drupalsib-file-processed').on('change', function () {

        var iSize = 0;
        // Check filesize (not for IE).
        if (!$.browser.msie) {
          var files_array = $(this)[0].files;
          iSize = files_array.length > 0 ? files_array[0].size : 0;
        }
        var $message = $('#webform-filesize-message');
        if (iSize > 0 && iSize > I20DS.maxSize) {
          if ($message.length == 0) {
            $('#edit-profile-main-profile-field-logo-und-0-ajax-wrapper').before('<div id="webform-filesize-message" class="alert alert-error"></div>');
            $message = $('#webform-filesize-message');
          }
          // Format size.
          $message.html(Drupal.t('Upload file larger than the maximum file size:<ul><li>- Current file size: <strong>@upload</strong></li><li>- Maximum file size: <strong>@maximum</strong></li></ul>',{
            '@upload': I20DS.formatFileSize(iSize),
            '@maximum': I20DS.formatFileSize(I20DS.maxSize)
          }));
          this.value = '';
          return false;
        }
        else {
          $message.remove();
        }
      });
    }
  }

})(jQuery, Drupal, this, this.document);
