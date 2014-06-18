<?php
/**
 * @file
 * Page.
 */
?>
<div class="icontent-area">             
  <div class="block-content-header2">
    <h2 class="suptitle"><?php print $title; ?></h2>
  </div>
  <div class="content-inner-wrapper">
    <div class="ds_content-left">
      <div class="content">
        <?php if (!empty($body)): ?>
          <?php print $body; ?>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
