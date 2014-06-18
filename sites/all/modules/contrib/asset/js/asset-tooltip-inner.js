/**
 * @file
 * Asset tooltip javascript for iframe.
 */
(function ($) {
  Drupal.behaviors.assetsTooltipResize = {
    attach: function (context) {
      var $link_active = parent.jQuery('.preview-active');

      if ($link_active.length == 1 && typeof($link_active.get(0).linked_iframe) == 'object') {
        setAssetSizes();
        setInterval(function () {
          setAssetSizes();
        }, 250);

        var parentScrollTop = parseInt($(parent).scrollTop());
      }

      function setAssetSizes() {
        var pageWidth = parseInt($('.tooltip-iframe-body-element').width()),
          pageHeight = parseInt($('.tooltip-iframe-body-element').height());

        var iframe = $link_active.get(0).linked_iframe,
          iframeWrapper = $link_active.get(0).linked_iframe_wrapper;

        iframe.width = pageWidth;
        iframe.height = pageHeight;
        $(iframeWrapper).removeClass('iframe-preview-loading');

        var itemHeight = parseInt($(iframeWrapper).height()),
          itemWidth = parseInt($(iframeWrapper).width()),
          itemOffsetTop = parseInt($(iframeWrapper).offset().top),
          itemOffsetLeft = parseInt($(iframeWrapper).offset().left),
          windowHeight = parseInt($(parent).height()),
          windowWidth = parseInt($(parent).width()),
          windowScrollTop = parseInt($(parent).scrollTop());

        if ((itemWidth + itemOffsetLeft) > windowWidth && itemOffsetLeft >= 0) {
          $(iframeWrapper).animate({
            marginLeft: windowWidth - itemOffsetLeft - itemWidth - 15 + 'px'
          }, 200);
        };
        setTimeout(function () {
          if ((itemHeight + itemOffsetTop) > (windowHeight + windowScrollTop) && itemOffsetTop >= 0 && parentScrollTop == windowScrollTop) {
            $(iframeWrapper).animate({
              top: itemOffsetTop + windowHeight + windowScrollTop - itemHeight - itemOffsetTop - 20 + 'px'
            }, 300);
          };
        }, 400);
      }
    }
  }
})(jQuery);
