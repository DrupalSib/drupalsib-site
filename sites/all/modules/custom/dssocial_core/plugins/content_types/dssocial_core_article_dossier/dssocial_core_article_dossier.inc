<?php
/**
 * @file
 * Theme functions for articles dossier this theme.
 */

$plugin = array(
  'title' => t('Article Dossier'),
  'description' => t('Article Dossier'),
  'category' => t('Dssocial core'),
  'hook theme' => 'dssocial_core_dssocial_core_article_dossier_content_type_theme',
  'all contexts' => TRUE,
);
/**
 * Returns content node.
 */
function dssocial_core_dssocial_core_article_dossier_content_type_render($subtype, $conf, $panel_args, $context) {
  $content = '';
  $output = '';
  $context = dssocial_core_get_context_by_type($context, 'node');
  $node = $context->data;
  foreach ($node->field_dossier_content[LANGUAGE_NONE] as $tids) {
    $tid = $tids['target_id'];
    if ($content != '') {
      $content .= '+' . $tid;
    }
    else {
      $content .= $tid;
    }
  }
  $content = views_embed_view('content_list', 'dossier_content', $content);
  if (!empty($content)) {
    $output = theme('dssocial_core_article_dossier', array('content' => $content));
  }
  $block = new stdClass();
  $block->content = $output;
  return $block;
}

/**
 * Theme functions for articles this theme.
 */
function dssocial_core_dssocial_core_article_dossier_content_type_theme(&$theme, $plugin) {
  $theme['dssocial_core_article_dossier'] = array(
    'path' => $plugin['path'],
    'template' => 'dssocial-core-article-dossier',
  );
}
