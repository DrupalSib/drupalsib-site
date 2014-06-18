<?php
/**
 * @file
 * Views export.
 */

/**
 * Implements hook_views_default_views().
 */
function asset_views_default_views() {
  $views = array();

  $view = new view;
  $view->name = 'assets_library';
  $view->description = 'Media';
  $view->tag = 'dashboard';
  $view->base_table = 'asset';
  $view->human_name = 'Assets library';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Media assets library';
  $handler->display->display_options['use_more_text'] = '';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer assets';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'asset';
  $handler->display->display_options['row_options']['view_mode'] = 'tooltip';
  $handler->display->display_options['row_options']['asset_library'] = 1;
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
  $handler->display->display_options['fields']['aid']['label'] = '';
  $handler->display->display_options['fields']['aid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['aid']['element_label_colon'] = FALSE;
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'asset';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['asset_tooltip'] = 'tooltip';
  /* Sort criterion: Media Asset: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'asset';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Media Asset: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'asset';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  /* Filter criterion: Media Asset: Asset type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'asset';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'uid';
  $handler->display->display_options['filters']['name']['operator'] = 'starts';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Author';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['required'] = 0;
  $handler->display->display_options['filters']['name']['expose']['multiple'] = FALSE;

  /* Display: Library */
  $handler = $view->new_display('page', 'Library', 'library');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['path'] = 'admin/assets/search';

  /* Display: Table */
  $handler = $view->new_display('page', 'Table', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'aid' => 'aid',
    'title' => 'title',
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
    'title' => array(
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
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Media Asset: Asset type */
  $handler->display->display_options['relationships']['type']['id'] = 'type';
  $handler->display->display_options['relationships']['type']['table'] = 'asset';
  $handler->display->display_options['relationships']['type']['field'] = 'type';
  $handler->display->display_options['relationships']['type']['required'] = 1;
  /* Relationship: Media Asset: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'asset';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Media Asset: Aid */
  $handler->display->display_options['fields']['aid']['id'] = 'aid';
  $handler->display->display_options['fields']['aid']['table'] = 'asset';
  $handler->display->display_options['fields']['aid']['field'] = 'aid';
  $handler->display->display_options['fields']['aid']['label'] = '';
  $handler->display->display_options['fields']['aid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['aid']['element_label_colon'] = FALSE;
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'asset';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
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
  /* Field: Asset type: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'asset_type';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'type';
  $handler->display->display_options['fields']['name']['label'] = 'Type';
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
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name_1']['label'] = 'Author';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name_1']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name_1']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name_1']['format_username'] = 1;
  /* Field: Media Asset: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'asset';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Сreated';
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
  /* Field: Media Asset: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'asset';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Сhanged';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Media Asset: Insert button */
  $handler->display->display_options['fields']['insert_asset']['id'] = 'insert_asset';
  $handler->display->display_options['fields']['insert_asset']['table'] = 'asset';
  $handler->display->display_options['fields']['insert_asset']['field'] = 'insert_asset';
  $handler->display->display_options['fields']['insert_asset']['label'] = 'Insert';
  $handler->display->display_options['fields']['insert_asset']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['insert_asset']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['insert_asset']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['insert_asset']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['insert_asset']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['insert_asset']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['insert_asset']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['insert_asset']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['insert_asset']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['insert_asset']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['insert_asset']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['insert_asset']['alter']['html'] = 0;
  $handler->display->display_options['fields']['insert_asset']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['insert_asset']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['insert_asset']['hide_empty'] = 0;
  $handler->display->display_options['fields']['insert_asset']['empty_zero'] = 0;
  $handler->display->display_options['fields']['insert_asset']['hide_alter_empty'] = 1;
  $handler->display->display_options['path'] = 'admin/assets/search';

  /* Display: Administration listing */
  $handler = $view->new_display('page', 'Administration listing', 'admin');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'aid' => 'aid',
    'title' => 'title',
    'name' => 'name',
    'name_1' => 'name_1',
    'created' => 'created',
    'changed' => 'changed',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'aid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Media Asset: Asset type */
  $handler->display->display_options['relationships']['type']['id'] = 'type';
  $handler->display->display_options['relationships']['type']['table'] = 'asset';
  $handler->display->display_options['relationships']['type']['field'] = 'type';
  $handler->display->display_options['relationships']['type']['required'] = 1;
  /* Relationship: Media Asset: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'asset';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Media Asset: Aid */
  $handler->display->display_options['fields']['aid']['id'] = 'aid';
  $handler->display->display_options['fields']['aid']['table'] = 'asset';
  $handler->display->display_options['fields']['aid']['field'] = 'aid';
  $handler->display->display_options['fields']['aid']['label'] = '';
  $handler->display->display_options['fields']['aid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['aid']['element_label_colon'] = FALSE;
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'asset';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
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
  $handler->display->display_options['fields']['title']['asset_tooltip'] = 'tooltip';
  /* Field: Asset type: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'asset_type';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'type';
  $handler->display->display_options['fields']['name']['label'] = 'Type';
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
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name_1']['label'] = 'Author';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name_1']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name_1']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name_1']['format_username'] = 1;
  /* Field: Media Asset: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'asset';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Сreated';
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
  /* Field: Media Asset: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'asset';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Сhanged';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Media Asset: Edit link */
  $handler->display->display_options['fields']['edit_asset']['id'] = 'edit_asset';
  $handler->display->display_options['fields']['edit_asset']['table'] = 'asset';
  $handler->display->display_options['fields']['edit_asset']['field'] = 'edit_asset';
  $handler->display->display_options['fields']['edit_asset']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_asset']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_asset']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_asset']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_asset']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_asset']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_asset']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_asset']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_asset']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_asset']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['edit_asset']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_asset']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_asset']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_asset']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['edit_asset']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_asset']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_asset']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_asset']['hide_alter_empty'] = 1;
  /* Field: Media Asset: Delete link */
  $handler->display->display_options['fields']['delete_asset']['id'] = 'delete_asset';
  $handler->display->display_options['fields']['delete_asset']['table'] = 'asset';
  $handler->display->display_options['fields']['delete_asset']['field'] = 'delete_asset';
  $handler->display->display_options['fields']['delete_asset']['label'] = 'Delete';
  $handler->display->display_options['fields']['delete_asset']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_asset']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_asset']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_asset']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['delete_asset']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['delete_asset']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delete_asset']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_asset']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_asset']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['delete_asset']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_asset']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_asset']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_asset']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['delete_asset']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete_asset']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_asset']['empty_zero'] = 0;
  $handler->display->display_options['fields']['delete_asset']['hide_alter_empty'] = 1;
  $handler->display->display_options['path'] = 'admin/content/assets';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Media assets';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;

  $translatables['assets_library'] = array(
    t('Master'),
    t('Media assets library'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Title'),
    t('Type'),
    t('Library'),
    t('more'),
  );

  $views[$view->name] = $view;

  return $views;
}
