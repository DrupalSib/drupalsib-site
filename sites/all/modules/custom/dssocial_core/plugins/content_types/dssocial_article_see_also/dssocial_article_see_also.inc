<?php
/**
 * @file
 * Theme functions for articles this theme.
 */

$plugin = array(
  'title' => t('Article see also'),
  'description' => t('Article see also'),
  'category' => t('Dssocial core'),
  'hook theme' => 'dssocial_core_dssocial_article_see_also_content_type_theme',
  'all contexts' => TRUE,
);

/**
 * Returns content node.
 */
function dssocial_core_dssocial_article_see_also_content_type_render($subtype, $conf, $panel_args, $context) {
  $conf['title'] = !empty($conf['override_title_text']) ? $conf['override_title_text'] : t('on the same theme');
  $context = dssocial_core_get_context_by_type($context, 'node');
  $node = $context->data;
  $output = '';
  if (!empty($node)) {
    $tids = '';
    if (!empty($node->field_tags)) {
      foreach ($node->field_tags[LANGUAGE_NONE] as $tid) {
        $tids[] = $tid['target_id'];
      }
      $tids = implode('+', $tids);
    }
    $results = views_get_view_result('article_list', 'articles_theme', $tids, $node->nid);
    if (!empty($results)) {
      foreach ($results as $key => $result) {
        // Link.
        $articles_also[$key]['link'] = url('node/' . $result->nid);
        // Title.
        $articles_also[$key]['title'] = dssocial_core_trim_title($result->node_title, 45);
        // Image.
        if (!empty($result->field_field_image)) {
          $articles_also[$key]['image'] = theme('image_style', array(
            'path' => $result->field_field_image[0]['raw']['uri'],
            'style_name' => 'articles_image',
          ));
        }
      }
      if (!empty($articles_also)) {
        $output = theme('dssocial_article_see_also', array('articles_also' => $articles_also, 'conf' => $conf));
      }
    }
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
};

/**
 * Theme functions for articles this theme.
 */
function dssocial_core_dssocial_article_see_also_content_type_theme(&$theme, $plugin) {
  $theme['dssocial_article_see_also'] = array(
    'path' => $plugin['path'],
    'template' => 'dssocial-article-see-also',
  );
}

/**
 * Implements hook_content_type_edit_form().
 */
function dssocial_core_dssocial_article_see_also_content_type_edit_form($form, &$form_state) {
  return $form;
}
