<?php
/**
 * @file
 * Asset gallery views export.
 */

/**
 * Implements hook_views_default_views().
 */
function asset_gallery_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'gallery_asset_dialog';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'asset';
  $view->human_name = 'Gallery asset dialog';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'aid' => 'aid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'aid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 1;
  /* Relationship: Media Asset: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'asset';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  /* Field: Media Asset: Aid */
  $handler->display->display_options['fields']['aid']['id'] = 'aid';
  $handler->display->display_options['fields']['aid']['table'] = 'asset';
  $handler->display->display_options['fields']['aid']['field'] = 'aid';
  $handler->display->display_options['fields']['aid']['label'] = 'Asset Id';
  $handler->display->display_options['fields']['aid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['aid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['aid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['aid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['aid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['aid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['aid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['aid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['aid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['aid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['aid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['aid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['aid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['aid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['aid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['aid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['aid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['aid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['aid']['asset_tooltip'] = 0;
  /* Field: Media Asset: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'asset';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_asset'] = FALSE;
  $handler->display->display_options['fields']['title']['asset_tooltip'] = 'tooltip';
  /* Field: Media Asset: Image */
  $handler->display->display_options['fields']['field_asset_image']['id'] = 'field_asset_image';
  $handler->display->display_options['fields']['field_asset_image']['table'] = 'field_data_field_asset_image';
  $handler->display->display_options['fields']['field_asset_image']['field'] = 'field_asset_image';
  $handler->display->display_options['fields']['field_asset_image']['label'] = 'Preview';
  $handler->display->display_options['fields']['field_asset_image']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_asset_image']['alter']['text'] = '<span rel="assets/tooltip/[aid]/tooltip" class="asset-tooltip">[field_asset_image]</span>';
  $handler->display->display_options['fields']['field_asset_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_asset_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_asset_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_asset_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_asset_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_asset_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_asset_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_asset_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_asset_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_asset_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_asset_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_asset_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_asset_image']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_asset_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_asset_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_asset_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_asset_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_asset_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_asset_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_asset_image']['field_api_classes'] = 0;
  /* Field: Media Asset: Copyright */
  $handler->display->display_options['fields']['field_asset_image_copyright']['id'] = 'field_asset_image_copyright';
  $handler->display->display_options['fields']['field_asset_image_copyright']['table'] = 'field_data_field_asset_image_copyright';
  $handler->display->display_options['fields']['field_asset_image_copyright']['field'] = 'field_asset_image_copyright';
  $handler->display->display_options['fields']['field_asset_image_copyright']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_asset_image_copyright']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_asset_image_copyright']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_asset_image_copyright']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_asset_image_copyright']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_asset_image_copyright']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_asset_image_copyright']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_asset_image_copyright']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_asset_image_copyright']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_asset_image_copyright']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_asset_image_copyright']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_asset_image_copyright']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_asset_image_copyright']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_asset_image_copyright']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_asset_image_copyright']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_asset_image_copyright']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_asset_image_copyright']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_asset_image_copyright']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_asset_image_copyright']['field_api_classes'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Media Asset: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'asset';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Sort criterion: Media Asset: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'asset';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Media Asset: Asset type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'asset';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'image' => 'image',
  );
  /* Filter criterion: Media Asset: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'asset';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['required'] = 0;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'uid';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Author';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['required'] = 0;
  $handler->display->display_options['filters']['name']['expose']['multiple'] = FALSE;

  /* Display: Gallery dialog Search */
  $handler = $view->new_display('references_dialog', 'Gallery dialog Search', 'references_dialog_1');
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['attach'] = array(
    0 => 'asset:field_asset_gallery_images:gallery',
  );
  $export['gallery_asset_dialog'] = $view;

  return $export;
}
