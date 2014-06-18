<?php
/**
 * @file
 * Display dossier node in teaser build mode.
 *
 * @see template_preprocess_node__dossier_teaser()
 */
?>
<div class="block_item">
  <?php if (!empty($image)): ?>
    <div class="block_img">
      <?php print $image; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($category)): ?>
    <h4><?php print $category; ?></h4>
  <?php endif; ?>
  <?php if (!empty($date)): ?>
    <span class="info"><?php print $date; ?></span>
  <?php endif; ?>
  <h5><?php print $title_link; ?></h5>
    <?php if (!empty($description)): ?>
      <p><?php print $description; ?></p>
    <?php endif; ?>
  <?php if (!empty($tags)): ?>
  <div class="block-motscles"><b><?php print t('tags'); ?></b>
    <?php print $tags; ?>
  </div>
  <?php endif; ?>
</div>
