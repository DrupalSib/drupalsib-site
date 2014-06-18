<?php
/**
 * @file
 * Field handler to present a library button.
 */

/**
 * Field handler to present a link to the entity.
 */
class asset_views_handler_field_asset_link extends views_handler_field_entity {

  /**
   * Provide appropriate default options for a handler.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    return $options;
  }

  /**
   * Provide options form for a handler.
   */
  function options_form(&$form, &$form_state) {
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );

    parent::options_form($form, $form_state);

    // The path is set by render_link function so don't allow to set it.
    $form['alter']['path'] = array('#access' => FALSE);
    $form['alter']['external'] = array('#access' => FALSE);
  }

  /**
   * Return HTML.
   */
  function render($values) {
    drupal_add_css(ASSET_MODULE_PATH . '/css/assets-library.css');

    if ($entity = $this->get_value($values)) {
      return $this->render_link($entity, $values);
    }
  }
}
