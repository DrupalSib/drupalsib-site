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
class asset_views_handler_field_asset_link_delete extends asset_views_handler_field_asset_link {

  /**
   * Return HTML.
   */
  function render_link($asset, $values) {
    // Ensure user have access to delete this entity.
    if (!entity_access('delete', 'asset', $asset)) {
      return;
    }

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "admin/content/assets/manage/$asset->aid/delete";
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    return $text;
  }
}
