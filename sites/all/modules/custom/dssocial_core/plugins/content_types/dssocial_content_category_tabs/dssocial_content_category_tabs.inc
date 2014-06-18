<?php
/**
 * @file
 * Theme functions Content category tabs.
 */

$plugin = array(
  'title' => t('Content category tabs'),
  'description' => t('Content category tabs'),
  'category' => t('Dssocial core'),
  'hook theme' => 'dssocial_core_dssocial_content_category_tabs_content_type_theme',
  'all contexts' => TRUE,
);

/**
 * Returns tabs.
 */
function dssocial_core_dssocial_content_category_tabs_content_type_render($subtype, $conf, $panel_args, $context) {

  $vars['link_comments'] = l(
    t('comments'), 'taxonomy/term/' . $panel_args[0] . '/comments', array(
      'attributes' => array(
        'id' => 'click-comments',
      ),
    )
  );

  $vars['link_popularity'] = l(
    t('popularity'), 'taxonomy/term/' . $panel_args[0] . '/popularity', array(
      'attributes' => array(
        'id' => 'click-content',
      ),
    )
  );

  if (!empty($vars)) {
    $output = theme('dssocial_content_category_tabs', $vars);
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
};

/**
 * Theme functions Content category tabs.
 */
function dssocial_core_dssocial_content_category_tabs_content_type_theme(&$theme, $plugin) {
  $theme['dssocial_content_category_tabs'] = array(
    'path' => $plugin['path'],
    'template' => 'dssocial-content-category-tabs',
  );
}
