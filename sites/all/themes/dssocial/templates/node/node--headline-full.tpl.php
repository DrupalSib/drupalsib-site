<?php
/**
 * @file
 * @see template_preprocess_node()
 */
?>
<div class="cell" data-cell="<?php print $number; ?>">
  <?php if (!empty($image)): ?>
    <?php print $image; ?>
  <?php endif; ?>
  <span class="<?php print $class; ?>"></span>
  <div class="cell-overlay">
    <div class="overlay-content">
      <div class="tags"></div>
      <h3 class="title" <?php if(!empty($title_color)): ?>style="color: <?php print $title_color; ?>"<?php endif; ?>>
        <?php print $title; ?>
      </h3>
    </div>
  </div>
  <?php print $link; ?>
</div>
