<?php
/**
 * @file
 * Theme functions RSS page.
 */

$plugin = array(
  'title' => t('RSS page'),
  'description' => t('RSS page'),
  'category' => t('Dssocial core'),
  'hook theme' => 'dssocial_core_dssocial_rss_page_content_type_theme',
  'all contexts' => TRUE,
);

/**
 * Returns RSS page.
 */
function dssocial_core_dssocial_rss_page_content_type_render($subtype, $conf, $panel_args, $context) {
  $output = '';
  $view = views_get_view_result('frontpage', 'rss_list');

  if (!empty($view)) {
    $img = theme(
      'image', array(
        'path' => DSSOCIAL_CORE_IMAGE_PATH . '/ico-rss.jpg',
      )
    );
    $section_title = array();
    foreach ($view as $section) {
      $sections[] = array(
        'title' => l($section->node_title, "rss/node/$section->nid"),
        'img' => l($img, "rss/node/$section->nid", array('html' => TRUE)),
      );
    }

    $output = theme('dssocial_rss_page', array('sections' => $sections));
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
};

/**
 * Theme functions RSS page.
 */
function dssocial_core_dssocial_rss_page_content_type_theme(&$theme, $plugin) {
  $theme['dssocial_rss_page'] = array(
    'path' => $plugin['path'],
    'template' => 'dssocial-rss-page',
  );
}
