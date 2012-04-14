<?php

/**
 *   
 */
?>
<div class="ds_sidebar_content">
  <div id="ds_fb_block">
      <script type="text/javascript" src="http://userapi.com/js/api/openapi.js?49"></script>

      <!-- VK Widget -->
      <div id="vk_groups"></div>
      <script type="text/javascript">
      VK.Widgets.Group("vk_groups", {mode: 0, width: "220", height: "430"}, 26642114);
      </script>
  </div>
  <div id="ds_tw_block">
    <script charset="utf-8" src="http://widgets.twimg.com/j/2/widget.js"></script>
    <script>
    new TWTR.Widget({
    version: 2,
    type: 'profile',
    rpp: 4,
    interval: 30000,
    width: 220,
    height: 300,
    theme: {
    shell: {
      background: '#9e9e9e',
      color: '#ffffff'
    },
    tweets: {
      background: '#e0e0e0',
      color: '#241f24',
      links: '#1453cf'
    }
    },
    features: {
    scrollbar: false,
    loop: false,
    live: false,
    behavior: 'all'
    }
    }).render().setUser('DrupalSib').start();
    </script>
  </div>
</div>