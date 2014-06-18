<?php

function drupalsib_preprocess_node(&$vars, $hook) {
  $node = $vars['node'];
  $view_mode = $vars['view_mode'];
  $preprocess = 'drupalsib_preprocess_node__' . $node->type . '_' . str_replace('-', '_', $view_mode);
  if (function_exists($preprocess)) {
    $preprocess($vars, $hook);
  } 
  $vars['theme_hook_suggestions'][] = 'node__' . $node->type . '_' . str_replace('-', '_', $view_mode);
}

function drupalsib_preprocess_node__headline_teaser(&$vars) {
  // Description.
  if (!empty($vars['field_description'])) {
    $vars['description'] = truncate_utf8($vars['field_description'][LANGUAGE_NONE][0]['value'], 150, TRUE, TRUE);
  }
  // Image.
  $vars['image'] = theme('image_style', array(
    'path' => $vars['field_headline_image'][LANGUAGE_NONE][0]['uri'],
    'style_name' => 'headline_view_teaser',
    'alt' => !empty($vars['field_headline_image'][LANGUAGE_NONE][0]['alt']) ? $vars['field_headline_image'][LANGUAGE_NONE][0]['alt'] : $vars['title']
  ));
  // Select gradient.
  if (!$vars['field_headline_gradient'][LANGUAGE_NONE][0]['value']) {
    $vars['class'] = 'ds_description_white';
  }
  else {
    $vars['class'] = 'ds_description';
  }
  // Link.
  $vars['link'] = '#';
  if (!empty($vars['field_headline_reference'])) {
    $vars['link'] = url('node/' . $vars['field_headline_reference'][LANGUAGE_NONE][0]['target_id']);
  }
}

function drupalsib_preprocess_node__headline_full(&$vars) {
  static $number = 0;
  $vars['number'] = $number; 
  $number++;
  // Image. 
  $vars['image'] = theme('image_style', array(
    'path' => $vars['field_headline_image'][0]['uri'],
    'style_name' => 'slider_list_view',
    'alt' => !empty($vars['field_headline_image'][0]['alt']) ? $vars['field_headline_image'][0]['alt'] : $vars['title'],
    'attributes' => array('class' => array('cell-image')),
  ));
  // Link.
  $vars['link'] = '#';
  if (!empty($vars['field_headline_reference'])) {
    $vars['link'] = url('node/' . $vars['field_headline_reference'][0]['target_id']);
  }
}

function drupalsib_preprocess_node__dossier_full(&$vars) {
  $node = $vars['node'];
  // Description
  $vars['description'] = $node->field_dossier_description['und'][0]['value'];
  // Title
  $vars['title'] = $node->title;
  //Content
  $vars['content_list'] = NULL;
}

//function drupalsib_preprocess_panels_pane(&$vars) {
//  switch ($vars['pane']->type) {
//    case 'page_content':
//    case 'node_content':
//      $vars['title'] = '';
//      break;
//  }
//}