<?php
/**
 * @file
 * Row style plugin for displaying the results as assets.
 */

/**
 * Plugin class for displaying Views results with entity_view.
 */
class asset_views_plugin_row_asset_view extends entity_views_plugin_row_entity_view {

  public function option_definition() {
    $options = parent::option_definition();
    $options['asset_library'] = array('default' => FALSE, 'boolean' => TRUE);

    return $options;
  }

  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['asset_library'] = array(
      '#type' => 'checkbox',
      '#title' => t('Render as an assets library item.'),
      '#description' => t('Turn it on for the ckeditor library listings.'),
      '#default_value' => $this->options['asset_library'],
    );
  }

  public function render($values) {
    drupal_add_css(ASSET_MODULE_PATH . '/css/assets-library.css');

    if ($entity = $this->get_value($values)) {
      $render = $this->rendered_content[$entity->aid];
      $render['#prefix'] = '<div class="assets-library-item-wrapper">
        <button type="button" class="assets-item-button" id="asset-item-' . $entity->aid . '-' . $entity->type . '">' . t('Add to editor') . '</button>';
      $render['#suffix'] = '</div>';

      return drupal_render($render);
    }
  }
}
