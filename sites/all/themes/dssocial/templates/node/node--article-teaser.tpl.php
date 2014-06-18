<?php
/**
 * @file
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
?>
<div class="block_item">
  <?php if (!empty($image)): ?>
    <div class="block_img">
      <div class="ds_article_teaser_image">
        <?php print $image; ?>
      </div>
    </div>
  <?php endif; ?>
  <?php if (!empty($content_category_name)): ?>
    <h4><?php print $content_category_name; ?></h4>
  <?php endif; ?>
  <?php if (!empty($date)): ?>
    <span class="info"><?php print $date; ?></span>
  <?php endif; ?>
  <h5><?php print $title_link; ?></h5>
  <?php if (!empty($summary)): ?>
    <span class="from"><?php print $summary; ?></span>
  <?php endif; ?>
  <?php if (!empty($description)): ?>
    <p><?php print $description; ?></p>
  <?php endif; ?>
  <?php if (!empty($core_content_tags)): ?>
  <div class="block-motscles"><b><?php print t('tags '); ?></b>
    <?php print $core_content_tags; ?>
  </div>
  <?php endif; ?>
</div>
