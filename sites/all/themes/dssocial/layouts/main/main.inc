<?php
/**
 * @file
 * Layout for main
 */

// Plugin definition.
$plugin = array(
  'title' => t('Main'),
  'category' => t('Dssocial'),
  'icon' => 'main.png',
  'theme' => 'dssocial_main',
  'css' => 'main.css',
  'regions' => array(
    'header' => t('Header'),
    'content' => t('Content'),
    'sidebar' => t('Sidebar'),
    'sidebar_bottom' => t('Sidebar Bottom'),
    'footer_top' => t('Footer Top'),
    'footer_bottom' => t('Footer Bottom'),
  ),
);
