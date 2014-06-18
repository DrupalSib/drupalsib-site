<?php
/**
 * @file
 * Field handler to present a library button.
 */

/**
 * Field handler to present a library button.
 *
 * @ingroup views_field_handlers
 */
class asset_views_handler_field_asset_link_insert extends asset_views_handler_field_asset_link {

  /**
   * Return HTML.
   */
  function render_link($asset, $values) {
    $this->options['alter']['make_link'] = FALSE;
    $text = !empty($this->options['text']) ? $this->options['text'] : t('Add to editor');
    return '<button type="button" class="assets-item-button" id="asset-item-' . $asset->aid . '-' . $asset->type . '">' . $text . '</button>';
  }
}
