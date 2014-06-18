<?php
/**
 * @file
 * Article dossier this theme.
 */
?>
<?php if (!empty($content)): ?>
  <?php print $content; ?>
<?php else: ?>
  <h3><?php print t('К этому досье не прикреплено ни одной статьи'); ?></h3>
<?php endif; ?>
