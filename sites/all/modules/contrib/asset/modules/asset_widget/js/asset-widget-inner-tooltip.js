/**
 * Asset search widget tooltip related JS actions.
 */

/**
 * Behaviour needed for passing iframe size to parent window function and enablet theme scroll.
 */
(function ($) {
  Drupal.behaviors.assetsWidgetTooltipResize = {
    attach:function (context) {
       var $context = $(context);

      // Hack, set wrapper height to object height.
      // It's needed because FF can't calculate proper height() in case of video asset.
      var $object = $context.find('object');
      if ($object.size()) {
        $object.parent().height($object.height());
      }

      // Get size of loaded frame.
      var frameWidth = $context.find('.tooltip-iframe-body-element').width();
      var frameHeight = $context.find('.tooltip-iframe-body-element').height();

      // Resize tooltip.
      if (parent && parent.assetWidget) {
        parent.assetWidget.tooltipsPositionCalc(frameWidth, frameHeight);
      }

      if ($.fn.jScrollPane) {
        // Store JScroll instance.
        var jscrollInstance;

        $('body').once(function () {
          var win = $(window);
          var isResizing = false;

          win.bind(
            'resize',
            function () {

              if (!isResizing) {
                isResizing = true;
                var $container = $context.find('body');
                // Temporarily make the container tiny so it doesn't influence the
                // calculation of the size of the document
                $container.css({
                  'width': 1,
                  'height': 1
                });
                // Now make it the size of the window...
                $container.css({
                  'width': win.width(),
                  'height': win.height()
                });
                isResizing = false;

                if (jscrollInstance) {
                  jscrollInstance.reinitialise();
                }
                else {
                  $container.jScrollPane({
                    enableKeyboardNavigation: false
                  });
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
          if ($context.find('.tooltip-iframe-body-element').width() != win.width()) {
            win.trigger('resize');
          }
        });
      }
    }
  }
})(jQuery);
