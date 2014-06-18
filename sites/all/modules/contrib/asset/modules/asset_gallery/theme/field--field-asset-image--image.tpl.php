<?php
/**
 * @file
 * Template for field--field-asset-image--image.
 */
?>
<?php if (count($items)): ?>
  <?php foreach ($items as $delta => $item): ?>
    <?php print render($item); ?>
  <?php endforeach; ?>
<?php endif; ?>
