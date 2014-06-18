<?php
/**
 * @file
 * dssocial_core_feature_content_article.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dssocial_core_feature_content_article_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dssocial_core_feature_content_article_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Статья'),
      'base' => 'node_content',
      'description' => t('Используйте <em>статьи</em> для создания новостей, пресс-релизов и сообщений в блоге.'),
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'help' => '',
    ),
  );
  return $items;
}
