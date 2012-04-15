<?php
/**
 * @file
 * @see template_preprocess_node()
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div id="ds_main_block">
    <a href="#">
      <span class="ds_image_box">
        <?php print $image; ?>
        <span class="ds_description_white"></span>
        <span class="ds_desc_text">
          <span class="title">
            <?php print $title; ?>
          </span>
          <?php print $description; ?>
        </span>
      </span>
    </a>
  </div>
</div>
