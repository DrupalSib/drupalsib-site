<?php

// Plugin definition
$plugin = array(
  'title' => t('Main'),
  'category' => t('Drupalsib'),
  'icon' => 'main.png',
  'theme' => 'drupalsib_main',
  'css' => 'main.css',
  'regions' => array(
    'header' => t('Header'),
    'content' => t('Content'),
    'sidebar_top' => t('Sidebar Top'),
    'sidebar' => t('Sidebar'),
    'sidebar_bottom' => t('Sidebar Bottom'),
    'footer_top' => t('Footer Top'),
    'footer_bottom' => t('Footer Bottom')
  ),
);
