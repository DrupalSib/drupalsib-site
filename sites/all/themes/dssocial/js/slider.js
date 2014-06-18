jQuery(document).ready(function(){
  dslider.createSlider('.slidebar-box-main');
});

dslider = {
  rotateSliders: function(gridid){
    jQuery(gridid).each(function() {
      var slider = jQuery(this);
      if(!slider.is('.mouseover')){
        dslider.goNext(slider);
      }
    });
  },
  createSlider: function(gridid) {
    jQuery(gridid).each(function() {
      var slider = jQuery(this);
      var slider_container = slider.children('.slidecont:first');
          
      slider_container.find('.cell').each(function(i){
        jQuery(this).attr('data-cell', i);
      });

      slider.mouseenter(function(){
        jQuery(this).addClass('mouseover');
      });
      
      slider.mouseleave(function(){
        jQuery(this).removeClass('mouseover');
      });

      dslider.addControls(slider);
      dslider.updateCounter(slider);
      dslider.goSlide(slider, 0)
    });
    
    dslider.checkElWidth();
    
    setInterval(function() {
      var g = gridid;
      dslider.rotateSliders(g);
    }, 6000);
  },
  
  checkElWidth: function() {
   
  },
    
  addControls: function(elm){
    if(elm.is('.has-slider-control-arrows')) { 
      arr_next = jQuery('<span>').attr('href','#').html('').addClass('slider-next').click(function(){
         
        }).appendTo(elm);
        
      arr_back = jQuery('<span>').attr('href','#').html('').addClass('slider-back').click(function(){
        
        }).appendTo(elm);
    }
    
    if(elm.is('.has-slider-dots')){
      dcontainer = jQuery('<div>').addClass('slider-dots').appendTo(elm);
      slider_container = elm.children('.slidecont:first');
      
      dots_count = slider_container.find('.cell').length;
      
      i = -1;
      while(i++, i < dots_count){
        d = jQuery('<a/>').attr('href','#').attr('data-button', i).addClass('dot');
        d.click(function(event){
          event.preventDefault();
          dslider.goSlide(jQuery(this).parents('.slider:first'), jQuery(this).attr('data-button'));
        });
        dcontainer.append(d);
      }
    }
    
    dslider.updateCounter(elm);
    dslider.checkElWidth();
        
  },
    
  goNext: function(elm){
    slidecont = elm.children('.slidecont:first');
    cslide = (parseInt(elm.attr('cslide'))) || 0;
    maxslide = slidecont.find('.cell').length - 1;
    next_slide = cslide + 1;
    if(next_slide > maxslide){
      next_slide = 0;
    }
    dslider.goSlide(elm, next_slide);  
    return;
  },
  
  goBack: function(elm){
    slidecont = elm.children('.slidecont:first');
    cslide = (parseInt(elm.attr('cslide'))) || 0;
    maxslide = slidecont.find('.cell').length - 1;
    prev_slide = cslide - 1;
    if(prev_slide < 0){
      prev_slide = maxslide;
    }
    dslider.goSlide(elm, prev_slide);  
    return;
  },
    
  goSlide: function(elm, n) {
    slidecont = elm.children('.slidecont');
    slidecont.find('.active').removeClass('active').fadeOut(500);
    slidecont.find('.cell').eq(n).addClass('active').fadeIn(500);
    elm.attr('cslide', n);
    dslider.updateCounter(elm);
    return;
  },
  
  updateCounter: function(elm){
    slider_container = elm.children('.slidecont:first');
    cslide = (parseInt(elm.attr('cslide'))) || 0;
    tslides = slider_container.find('.cell').length;
        
    if(elm.is('.has-slider-numbers')){ 
      numbers = elm.children('.dslider-numbers:first');
      slice_counter.html((cslide + 1) + Drupal.t(' sur ') + tslides );
    }
    if(elm.is('.has-slider-dots')){
      i = cslide;
      dots = elm.children('.slider-dots');
      dots.children('.active').removeClass('active');
      dots.find('.dot').eq(i).addClass('active');
    }

  }

}
