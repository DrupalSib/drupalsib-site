<?php
/**
 * @file
 * Contains the basic asset field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to an asset.
 * Definition terms:
 * - link_to_asset default: Should this field have the checkbox "link to node" enabled by default.
 *
 * @ingroup views_field_handlers
 */
class asset_views_handler_field_asset extends views_handler_field {

  /**
   * Initialize, don't add the additional fields to group by.
   */
  function init(&$view, &$options) {
    parent::init($view, $options);

    if (!empty($this->options['link_to_asset']) || !empty($this->options['asset_tooltip'])) {
      $this->additional_fields['aid'] = array('table' => 'asset', 'field' => 'aid');
    }
  }

  /**
   * Provide appropriate default options for a handler.
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['asset_tooltip'] = array('default' => '');
    $options['link_to_asset'] = array(
      'default' => isset($this->definition['link_to_asset default']) ? $this->definition['link_to_asset default'] : FALSE,
      'bool' => TRUE,
    );

    return $options;
  }

  /**
   * Provide options form for a handler.
   */
  function options_form(&$form, &$form_state) {
    $form['link_to_asset'] = array(
      '#title' => t('Link this field to the original piece of content'),
      '#description' => t("Enable to override this field's links."),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_asset']),
    );

    $entity_info = entity_get_info('asset');
    $options = array();
    if (!empty($entity_info['view modes'])) {
      foreach ($entity_info['view modes'] as $mode => $settings) {
        $options[$mode] = $settings['label'];
      }
    }

    if (empty($options)) {
      $options = array(
        'full' => t('Default'),
      );
    }
    $form['asset_tooltip'] = array(
      '#title' => t('Show an asset tooltip preview'),
      '#description' => t('Choose a desired view mode for a tooltip.'),
      '#type' => 'select',
      '#default_value' => !empty($this->options['asset_tooltip']) ? $this->options['asset_tooltip'] : '',
      '#options' => $options,
      '#empty_value' => 0,
    );

    parent::options_form($form, $form_state);
  }

  /**
   * Render whatever the data is as a link to the asset.
   */
  function render_link($data, $values) {
    if (!empty($this->additional_fields['aid'])) {
      if ($data !== NULL && $data !== '') {
        if (!empty($this->options['link_to_asset'])) {
          $this->options['alter']['make_link'] = TRUE;
          $this->options['alter']['path'] = "admin/content/assets/view/" . $this->get_value($values, 'aid');

          if (!empty($this->options['asset_tooltip'])) {
            drupal_add_library('asset', 'asset_tooltip');

            $view_mode = check_plain($this->options['asset_tooltip']);
            $this->options['alter']['link_class'] = 'asset-tooltip';
            $this->options['alter']['rel'] = 'assets/tooltip/' . $this->get_value($values, 'aid') . '/' . $view_mode;
          }
        }
        else {
          $this->options['alter']['make_link'] = FALSE;

          if (!empty($this->options['asset_tooltip'])) {
            drupal_add_library('asset', 'asset_tooltip');

            $view_mode = check_plain($this->options['asset_tooltip']);
            $this->options['alter']['alter_text'] = TRUE;
            $rel = 'assets/tooltip/' . $this->get_value($values, 'aid') . '/' . $view_mode;
            $this->options['alter']['text'] = '<span class="asset-tooltip" rel="' . $rel . '">' . $data . '</span>';
          }
        }
      }
    }

    return $data;
  }

  /**
   * Return HTML.
   */
  function render($values) {
    $value = $this->get_value($values);
    return $this->render_link($this->sanitize_value($value), $values);
  }
}
