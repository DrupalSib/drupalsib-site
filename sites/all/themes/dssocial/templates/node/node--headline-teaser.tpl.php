<?php
/**
 * @file
 * @see template_preprocess_node()
 */
?>
<div class="ds_main_block">
  <a href="<?php print $link; ?>">
    <span class="ds_image_box">
      <?php if (!empty($image)): ?>
        <?php print $image; ?>
      <?php endif; ?>
      <span class="<?php print $class; ?>"></span>
      <span class="ds_desc_text">
        <span class="title">
          <?php print $title; ?>
        </span>
        <?php if (!empty($description)): ?>
          <?php print $description; ?>
        <?php endif; ?>
      </span>
    </span>
  </a>
</div>
