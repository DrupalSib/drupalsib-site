<?php
/**
 * @file
 * Footer this theme.
 */
?>
<?php if (!empty($tags)): ?>
  <div class="ds_tags_name">
    <?php print t('tags :') ?>
  </div>
  <div class="ds_tags">
    <?php print $tags; ?>
  </div>
<?php endif; ?>
