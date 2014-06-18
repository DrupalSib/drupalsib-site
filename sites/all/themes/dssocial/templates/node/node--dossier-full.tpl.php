<?php
/**
 * @file
 * Display dossier node in full build mode.
 *
 * @see template_preprocess_node__dossier_full()
 */
?>
<div class="block-content-header">
  <h1><?php print $title; ?></h1>
  <?php if (!empty($tags)) : ?>
    <div class="block-motscles">
      <div class="block-for-motscles">
        <?php print t('tags :'); ?>
        <?php print $tags;?>
      </div>
    </div>
  <?php endif ?>
</div>
<div class="ds_social_dossier_full">
  <?php  if(!empty($description)): ?>
    <?php print $description; ?>
  <?php  endif; ?>
</div>
