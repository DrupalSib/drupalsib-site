<?php

/**
 * @file
 * Ctools content type menu categories
 */

/**
 * Implements hook_ctools_content_types().
 */
function menu_generator_custom_menu_ctools_content_types() {
  return array(
    'single'       => TRUE,
    'title'        => t('Custom menu'),
    'description'  => t('Render custom menu'),
    'all contexts' => TRUE,
    'category'     => t('Menu generator'),
    'icon'         => 'custom_menu.png',
    'hook theme'   => 'menu_generator_custom_menu_content_type_theme',
    'defaults' => array(
      'wrapper' => array(),
      'wrapper_element' => array(),
      'wrapper_element_page' => array(),
      'menus_list' => array()
    )
  );
}

/**
 * Implements hook_content_type_render().
 */
function menu_generator_custom_menu_content_type_render($subtype, $conf, $panel_args, $context) {
  if (!isset($conf['menus_list'])) {
    return;
  }
  $content = '';
  $results = menu_tree_page_data($conf['menus_list']);
  $menus = array();
  foreach ($results as $id => $result) {
    if (!$result['link']['hidden']) {
      $menus[$id]['title'] = $result['link']['link_title'];
      $menus[$id]['url'] = $result['link']['link_path'];
      $menus[$id]['active'] = $result['link']['in_active_trail'];
    }
  }
  
  if (!empty($menus)) {
    if (!empty($conf['wrapper_element'])) {
      foreach ($menus as $menu) {
        if (!$menu['active'] || empty($conf['wrapper_element_page'])) {
          $content .= str_replace(array('!title', '!url'), array($menu['title'], url($menu['url'])), $conf['wrapper_element']);
        }
        else {
          $content .= str_replace(array('!title', '!url'), array($menu['title'], url($menu['url'])), $conf['wrapper_element_page']);
        }
      }
    }
    else {
      foreach ($menus as $menu) {
        $content .= l($menu['title'], $menu['url']);
      }
    }
    if (!empty($content) && !empty($conf['wrapper'])) {
      $content = str_replace('!elements', $content, $conf['wrapper']);
    }
  }
  else {
    return;
  }
  
  $block = new stdClass();
  $block->content = $content;

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function menu_generator_custom_menu_content_type_theme(&$theme, $plugin) {
  $theme['menu_generator_custom_menu'] = array(
    'path'      => $plugin['path'],
    'template'  => 'custom-menu'
  );
}

/**
 * Implements hook_content_type_edit_form().
 */
function menu_generator_custom_menu_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  unset($form['override_title_text']);
  unset($form['override_title_markup']);
  unset($form['override_title']);
  
  $menus = db_select('menu_custom', 'mc')
    ->fields('mc', array('title', 'menu_name'))
    ->orderBy('mc.title')
    ->execute()
    ->fetchAllKeyed();

  if ($menus) {
    $form['menus_list'] = array(
      '#type'    => 'select',
      '#options' => array_flip($menus),
      '#default_value' => (isset($conf['menus_list'])) ? $conf['menus_list'] : '',
      '#title'   => t('Select menu to render'),
      '#required'   => TRUE,
    );
  }
  
  $form['wrapper'] = array(
    '#type'    => 'textarea',
    '#default_value' => (isset($conf['wrapper'])) ? $conf['wrapper'] : '',
    '#title'   => t('Menu wrapper'),
    '#description' => t('!elements: All elements menu')
  );
  
  $form['wrapper_element'] = array(
    '#type'    => 'textarea',
    '#default_value' => (isset($conf['wrapper_element'])) ? $conf['wrapper_element'] : '',
    '#title'   => t('Element wrapper'),
    '#description' => t('!title: Title menu element; !url: Url element menu')
  );
  
  $form['wrapper_element_page'] = array(
    '#type'    => 'textarea',
    '#default_value' => (isset($conf['wrapper_element_page'])) ? $conf['wrapper_element_page'] : '',
    '#title'   => t('Active element wrapper'),
    '#description' => t('!title: Title menu element; !url: Url element menu')
  );
  
  return $form;
}

/**
 * Implements hook_content_type_edit_form_submit().
 */
function menu_generator_custom_menu_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Returns the administrative title for a type.
 */
function menu_generator_custom_menu_content_type_admin_title($subtype, $conf) {
  return t('Menu "@menu"', array('@menu' => $conf['menus_list']));
}