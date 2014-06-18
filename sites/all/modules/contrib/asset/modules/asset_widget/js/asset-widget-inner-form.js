/**
 * Script related to assets create/edit forms in case of in-frame rendering.
 */

(function ($) {

  if ($.fn.jScrollPane) {
    // Store JScroll instance for easy re-init.
    var jscrollInstance;

    // Re-init scroll, if available.
    var assetChildReinitScroll = function () {
      if (jscrollInstance) {
        jscrollInstance.reinitialise();
      }
    };

    // Override default tableDrag to re-init scrolls.
    if (Drupal.tableDrag) {
      Drupal.tableDrag.prototype.onDrop = function () {
        assetChildReinitScroll();
        return null;
      };
    }
  }

  if (Drupal.ajax) {
    Drupal.ajax.prototype.originalBeforeSerialize = Drupal.ajax.prototype.beforeSerialize;
    Drupal.ajax.prototype.beforeSerialize = function (element, options) {
      // We always pass asset_frame to Drupal if available, to determine widget context in default ajax.
      if (Drupal.settings.assetWidget.assetFrame && options.url.indexOf('asset_frame') == -1) {
        options.url += options.url.indexOf('?') != -1 ? '&asset_frame=true' : '?asset_frame=true';

      }
      this.originalBeforeSerialize(element, options);
    };
  }

  Drupal.behaviors.asssetChildForm = {
    attach:function (context, settings) {
      var $context = $(context);
      if (parent.assetWidget) {
        var assetWidget = parent.assetWidget;
        // We show loader on submit, and it will be hidden on parent window side.
        $context.find('form').once(function () {
          $(this).submit(function () {
            assetWidget.showTabLoader();
          })
        });
      }

      // Re-init scroll on every attaching.
      assetChildReinitScroll();

      if ($.fn.jScrollPane) {
        $('body').once(function () {
          var win = $(window);
          var isResizing = false;

          win.bind(
            'resize',
            function () {

              if (!isResizing) {
                isResizing = true;
                var $container = $('.frame-page-wrapper');
                // Temporarily make the container tiny so it doesn't influence the
                // calculation of the size of the document
                $container.css({
                  'width':1,
                  'height':1
                });
                // Now make it the size of the window...
                $container.css({
                  'width':win.width(),
                  'height':win.height()
                });
                isResizing = false;

                if (jscrollInstance) {
                  jscrollInstance.reinitialise();
                }
                else {
                  $container.jScrollPane({enableKeyboardNavigation: false});
                  jscrollInstance = $container.data('jsp');
                }
              }
            }
          ).trigger('resize');

          // Workaround for known Opera issue which breaks demo (see
          // http://jscrollpane.kelvinluck.com/known_issues.html#opera-scrollbar )
          $('body').css('overflow', 'hidden');

          // IE calculates the width incorrectly first time round (it
          // doesn't count the space used by the native scrollbar) so
          // we re-trigger if necessary.
          if ($('.frame-page-wrapper').width() != win.width()) {
            win.trigger('resize');
          }
        });

        // Respect form height changes.
        $context.find('select.filter-list').change(function () {
          // Add tiny timeout, to let Wysiwyg be enabled/disabled.
          setTimeout(assetChildReinitScroll, 0);
        });
        // Respect split summary, editor switcher and collapsible fieldsets.
        $context.find('a.ckeditor_links, a.link-edit-summary, fieldset.collapsible a.fieldset-title').click(assetChildReinitScroll);

        // Re-init scroll on core grippie events.
        $context.find('.grippie').once(function () {
          $this = $(this);
          $this.mousedown(startDrag);

          function startDrag(e) {
            $(document).mouseup(endDrag);
            return false;
          }

          function endDrag(e) {
            $(document).unbind('mouseup', endDrag);
            assetChildReinitScroll();
          }
        });

        // Wysiwyg could add additional height to content, so re-init when it's complete.
        if (typeof CKEDITOR != 'undefined') {
          CKEDITOR.on('instanceReady', function () {
            assetChildReinitScroll();
          });
        }
      }
    }
  };
})(jQuery);
