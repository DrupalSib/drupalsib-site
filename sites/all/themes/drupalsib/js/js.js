jQuery(document).ready(function() {
  imageGallery();
});

function imageGallery() {
  jQuery('div.gallery-block').each(function(){
    var index;
    var $current;
    var $this = jQuery(this);
    var time = 1000;

    var $ui = jQuery("div.preview-image ul", $this);
    $ui.not(".processed-ui").jcarousel({
      scroll: 5,
      wrap: "both",
      animation: 500
    }).addClass("processed-ui");

    jQuery("body").append('<div class="wrapforimageinfo"></div>');
    var $wrap = jQuery("div.wrapforimageinfo");

    var $image = jQuery("div.main-image li", $this).css({
      opacity: 0,
      display: 'none'
    });
    jQuery("div.main-image li:first", $this).css({
      opacity: 1,
      display: 'block'
    });

    var $li = jQuery("li", $ui).css({
      opacity: 0.4
    });
    jQuery("li:first", $ui).css({
      opacity: 1
    }).addClass("active");

    if($li){
      $li.click(function(){
        var index = jQuery($li).index(this);
        $current = jQuery($li).eq(index).css({
          opacity: 1
        }).addClass("active");
        jQuery($li).not($current).css({
          opacity: 0.4
        }).removeClass("active");

        jQuery($image).not($current).stop().animate({
          opacity: 0
        }, time).css({
          display: 'none'
        });
        jQuery($image).eq(index).stop().animate({
          opacity: 1
        }, time).css({
          display: 'block'
        });
      });
      $li.mouseover(function(){
        var index = jQuery($li).index(this);
        if(!jQuery(this).hasClass("active")){
          jQuery($li).eq(index).stop().animate({
            opacity: 1
          }, 300);
        }
        if(!$ui.hasClass('disable-tips')){
          var $posT = parseFloat(jQuery(this).offset().top);
          var $posL = parseFloat(jQuery(this).offset().left);

          var $info = jQuery("span.block-imagegallery-info", $ui).eq(index).html();
          $wrap.html($info);

          var $infoHeight = parseFloat($wrap.height()) + 37;

          $wrap.css({
            top: $posT - $infoHeight + "px",
            left: $posL - 81 + "px"
          });
        }
      }).mouseout(function(){
        var index = jQuery($li).index(this);
        if(!jQuery(this).hasClass("active")){
          jQuery($li).eq(index).stop().animate({
            opacity: 0.4
          }, 100);
        }

        if(!$ui.hasClass('disable-tips')){
          $wrap.css({
            top: -9999 + "px",
            left: -9999 + "px"
          });
        }
      });
    }
  });



  /**
     * bind hotkeys here
     * Character codes:
     * 37 - left
     * 38 - up
     * 39 - right
     * 40 - down
     */

  jQuery(document).keydown(function (e) {
    var lenghtCurrent = jQuery('#viewer-nav-bottom li').size();

    switch (e.keyCode) {
      case 37:
        //jQuery('.jcarousel-prev').click();
        jQuery('#top-prev').click();
        var indexCurrent = +jQuery('#currSlide').text() - 1;
        // console.log(indexCurrent, lenghtCurrent);
        jQuery('#viewer-nav-bottom li').removeClass('active').css({
          opacity: 0.4
        });
        jQuery('#viewer-nav-bottom li').eq(indexCurrent).addClass('active').animate({
          opacity: 1
        });

        if (indexCurrent == 6) {
          jQuery("#viewer-nav-bottom .jcarousel-prev").click();
        }
        //jQuery('#deck-container').cycle();
        //jQuery('li[jcarouselindex=3]').click()
        break;
      case 39:
        //jQuery('.jcarousel-next').click();
        jQuery('#top-next').click();
        var indexCurrent = +jQuery('#currSlide').text() - 1;
        // console.log(indexCurrent, lenghtCurrent);
        if (indexCurrent == lenghtCurrent - 1) lenghtCurrent = 0;
        jQuery('#viewer-nav-bottom li').removeClass('active').css({
          opacity: 0.4
        });
        jQuery('#viewer-nav-bottom li').eq(indexCurrent).addClass('active').animate({
          opacity: 1
        });

        if (indexCurrent !== 0 && (indexCurrent == lenghtCurrent || indexCurrent % 5 == 0)) {
          jQuery("#viewer-nav-bottom .jcarousel-next").click();
        }
        break;
    }
  });
}
