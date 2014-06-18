<?php
/**
 * @file
 * Template for common part of asset search widget.
 */
?>
<div class="assets-module">
  <div class="assets-module-inner">
    <span class="show-control-wrap">
      <span class="top"></span>
			<span class="bottom"></span>
      <span class="show-control" title="<?php print t('Show/hide the assets'); ?>"></span>
    </span>

    <div class="assets-content">
      <div class="tab-contents">
        <div class="tab-contents-top-search"></div>
        <div class="tab-contents-bottom">
          <div class="top"></div>
          <div class="mid">
            <?php if (!empty($tab_links)): ?>
              <?php foreach ($tab_links as $tab_id => $link): ?>
                <div class="tab <?php print $tab_id; ?>-tab hidden"></div>
              <?php endforeach; ?>
            <?php endif; ?>
            <div class="loading hidden">
              <?php print $loader; ?>
            </div>
          </div>
          <div class="bottom"></div>
        </div>
      </div>
      <?php if (!empty($tab_links)): ?>
        <div class="tab-links">
          <?php print theme('links', array('links' => $tab_links)); ?>
          <div class="mask"></div>
        </div>
      <?php endif; ?>
    </div>
    <div class="active-tooltip-container">
      <div class="tooltip">
        <div class="tooltip-inner masked">
          <span class="pointer"></span>
          <div class="tooltip-content-wrapper"></div>
          <div class="loading">
            <?php print $loader; ?>
          </div>
          <a href="javascript: void(0)" class="close" title="<?php print t('Close popup'); ?>"><?php print t('close'); ?></a>
        </div>
      </div>
    </div>
  </div>
</div>
