/**
 * @file
 * Asset tooltip related javascript.
 */
(function ($) {
  Drupal.assets = Drupal.assets || {};
  Drupal.assets.initTooltips = function () {
    var resize = 0;
    $('.show-preview-element').remove();

    $('.asset-tooltip').each(function () {
      var $this = $(this),
        $image = $this.find('img'),
        action = null;

      if ($image.length) {
        // Prevent double event processing, that cause tooltip hide.
        if ($this.hasClass('processed')) {
          return;
        }
        action = $this[0];
        $(action).addClass('show-preview-element-image');
      }
      else {
        action = document.createElement('span');
        $(action).addClass('show-preview-element');
        $('body').append(action);
      }

      $this.addClass('processed');

      var thisWidth = parseInt($this.width());

      var hideAllPreviewElements = function () {
        $('.already-open').removeClass('already-open');
        $('.preview-active').removeClass('preview-active');
        $('.iframe-preview-wrapper').removeClass('iframe-preview-loading').remove();
      };

      var bodyClick = function () {
        $(document).bind('click.preview', function (e) {
          if (!$(e.target).parents('.iframe-preview-wrapper').length) {
            hideAllPreviewElements();
            $(document).unbind('click.preview');
          }
        });
      };

      setTimeout(function () {
        var thisOffset = $this.offset();
        $(action).css({
          opacity: 0,
          top: thisOffset.top + 3 + 'px',
          left: thisOffset.left + thisWidth + 10 + 'px'
        }).animate({opacity: 1}, 500);
      }, 2500);

      $(action).bind('click', function () {
        var $thisItem = $(this),
          thisOffset = $thisItem.offset();

        if (!$thisItem.hasClass('already-open')) {
          hideAllPreviewElements();

          $thisItem.addClass('already-open');

          var iframe = document.createElement('iframe'),
            wrapper = document.createElement('div'),
            url = $this.attr('rel');

          $thisItem.addClass('preview-active');

          iframe.scrolling = 'no';
          if (url.substr(0, 1) != '/') {
            url = Drupal.settings.basePath + url;
          }
          else {
            var base_url = Drupal.settings.basePath.split('/');
            url = '/' + base_url[1] + url;
          }

          $(iframe).attr('src', url);
          iframe.frameBorder = 0;
          iframe.width = 1000;
          iframe.height = 1000;
          $(iframe).attr('allowtransparency', 'true');
          iframe.className = 'iframe-preview';

          wrapper.className = 'iframe-preview-wrapper iframe-preview-loading';
          wrapper.appendChild(iframe);
          wrapper.style.top = thisOffset.top - 10 + 'px';
          if ($thisItem.hasClass('show-preview-element-image')) {
            $(wrapper).addClass('iframe-preview-wrapper-image');
            wrapper.style.left = thisOffset.left + $thisItem.width() + 10 + 'px';
          }
          else {
            wrapper.style.left = thisOffset.left + 20 + 'px';
          };

          this.linked_iframe = iframe;
          this.linked_iframe_wrapper = wrapper;

          $('body').append(wrapper);
        }
        else {
          hideAllPreviewElements();
        };

        bodyClick();

        setTimeout(function () {
          resize = 1;
        }, 100);

        return false;
      });

      $(window).resize(function () {
        var thisWidth = parseInt($this.width()),
          thisOffset = $this.offset();

        $(action).css({
          top: thisOffset.top + 3 + 'px',
          left: thisOffset.left + thisWidth + 10 + 'px'
        });

        if ($('body').hasClass('first-resize') && resize) {
          hideAllPreviewElements();
        }
        else {
          setTimeout(function () {
            $('body').addClass('first-resize');
          }, 100);
        };
      });
    });
  };

  Drupal.behaviors.assetsTooltip = {
    attach: function (context) {
      setTimeout(Drupal.assets.initTooltips, 2500);
    }
  }
})(jQuery);
