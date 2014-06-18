<?php
/**
 * @file
 * Template for asset gallery in full view mode.
 */
?>
<!--<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>> -->

  <strong <?php print $title_attributes; ?>>
      <?php print $title; ?>
  </strong>

  <div class="content"<?php print $content_attributes; ?>><?php
    $img_keys = element_children($content['field_asset_gallery_images']);
    $class = '';
    foreach ($img_keys as $key) {
      if (!empty($content['field_asset_gallery_images'][$key])) {
        $a_tag_part = drupal_render($content['field_asset_gallery_images'][$key]);
        if (!empty($a_tag_part)) {
          $out = '<a' . $class . ' rel="lightbox[' . $title . ']' . $a_tag_part;
          $class = ' class="lightbox_hide_image"';
          if (!$asset->in_editor) {
            print $out;
          }
          else {
            print strip_tags($out, '<img>');
            break;
          }
        }
      }
    }
    hide($content['field_asset_gallery_images']);
    print render($content);
  ?></div>
<!--</div> -->
