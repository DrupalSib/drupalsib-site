<?php
/**
 * @file
 * Field handler to present a link asset edit.
 */

/**
 * Field handler to present a link asset edit.
 *
 * @ingroup views_field_handlers
 */
class asset_views_handler_field_asset_link_edit extends asset_views_handler_field_asset_link {

  /**
   * Return HTML.
   */
  function render_link($asset, $values) {
    // Ensure that user have access to edit this entity.
    if (!entity_access('update', 'asset', $asset)) {
      return;
    }

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "admin/content/assets/manage/$asset->aid";
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    return $text;
  }
}
