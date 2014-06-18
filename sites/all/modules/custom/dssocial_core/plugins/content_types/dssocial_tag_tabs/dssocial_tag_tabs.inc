<?php
/**
 * @file
 * Theme functions Tag tabs.
 */

$plugin = array(
  'title' => t('Tag tabs'),
  'description' => t('Tag tabs'),
  'category' => t('Dssocial core'),
  'hook theme' => 'dssocial_core_dssocial_tag_tabs_content_type_theme',
  'all contexts' => TRUE,
);

/**
 * Returns tabs.
 */
function dssocial_core_dssocial_tag_tabs_content_type_render($subtype, $conf, $panel_args, $context) {

  $vars['link_comments'] = l(
    t('comments'), 'taxonomy/term/' . $panel_args[0] . '/tag/comments', array(
      'attributes' => array(
        'id' => 'click-comments',
      ),
    )
  );

  $vars['link_popularity'] = l(
    t('popularity'), 'taxonomy/term/' . $panel_args[0] . '/tag/popularity', array(
      'attributes' => array(
        'id' => 'click-content',
      ),
    )
  );

  if (!empty($vars)) {
    $output = theme('dssocial_tag_tabs', $vars);
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
};

/**
 * Theme functions Tag tabs.
 */
function dssocial_core_dssocial_tag_tabs_content_type_theme(&$theme, $plugin) {
  $theme['dssocial_tag_tabs'] = array(
    'path' => $plugin['path'],
    'template' => 'dssocial-tag-tabs',
  );
}
