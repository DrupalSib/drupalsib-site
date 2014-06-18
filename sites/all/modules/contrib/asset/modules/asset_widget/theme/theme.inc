<?php
/**
 * @file
 * Module related preprocesses and theme overrides.
 */

/**
 * Preprocess variables for asset-widget-wrapper.tpl.php.
 *
 * @see asset-widget-wrapper.tpl.php
 */
function template_preprocess_asset_widget_wrapper(&$vars) {
  $vars['tab_links'] = array();
  foreach (asset_widget_get_tabs_info() as $tab_id => $info) {
    $classes = array(
      $tab_id . '-tab',
    );

    if (!empty($info['classes'])) {
      $classes = array_merge($classes, $info['classes']);
    }

    $vars['tab_links'][$tab_id] = array(
      'href' => 'javascript:void(0)',
      'title' => '<span class="ico"></span>',
      'external' => TRUE,
      'html' => TRUE,
      'attributes' => array('class' => $classes, 'title' => isset($info['title']) ? t($info['title']) : ''),
    );
  }
  $vars['tabs_count'] = count($vars['tab_links']);

  $vars['loader'] = theme(
    'image',
    array(
      'path' => ASSET_WIDGET_MODULE_PATH . '/images/content/loader.gif' ,
      'attributes' => array(
        'alt' => t('Loading...'),
      ),
    )
  );
}

/**
 * Preprocess variables for asset-widget-edit-buttons.tpl.php.
 *
 * @see asset-widget-edit-buttons.tpl.php
 */
function template_preprocess_asset_widget_edit_buttons(&$vars) {
  if (!empty($vars['asset'])) {
    $vars['preview_link'] = l(
      '<span class="ico"></span>' . t('Preview'),
      "javascript: void(0)",
      array(
        'html' => TRUE,
        // To leave raw href.
        'external' => TRUE,
      )
    );

    // @todo after applying of custom perms patch, rework it.
    if (user_access('administer assets')) {
      $vars['edit_link'] = l(
        '<span class="ico"></span>' . t('Edit'),
        "admin/content/assets/manage/{$vars['asset']->aid}",
        array(
          'html' => TRUE,
          'attributes' => array(
            'id' => 'aid-' . $vars['asset']->type . '-' . $vars['asset']->aid,
            'target' => '_blank',
            'class' => 'asset-widget-modify-asset',
          ),
        )
      );
    }
  }
}

/**
 * Preprocess variables for asset-widget-search-filters-block.tpl.php.
 *
 * @see asset-widget-search-filters-block.tpl.php
 */
function template_preprocess_asset_widget_search_filters_block(&$vars) {
  $vars['search_labels'] = array();
  if (!empty($vars['search_params'])) {
    // Provide few links to short mode.
    $vars['search_labels'] = array_slice($vars['search_params'], 0, 3);
  }
}

/**
 * Preprocess variables for asset--widget-search.tpl.php.
 *
 * @see asset--widget-search.tpl.php
 */
function template_preprocess_asset__widget_search(&$vars) {
  // Run preprocesses for default asset types.
  $preprocess = 'template_preprocess_' . $vars['entity_type'] . '__' . $vars['asset']->type . '__' . $vars['view_mode'];
  if (function_exists($preprocess)) {
    $preprocess($vars);
  }

  $vars['buttons'] = theme(
    'asset_widget_edit_buttons',
    array(
      'asset' => $vars['asset'],
    )
  );

  $vars['view_mode_switch'] = theme('asset_widget_view_mode_switch_block', array('asset' => $vars['asset']));
}

/**
 * Preprocess variables for asset--image--widget-search.tpl.php.
 *
 * @see asset--image--widget-search.tpl.php
 */
function template_preprocess_asset__image__widget_search(&$vars) {
  // Listing content.
  $image = field_get_items('asset', $vars['asset'], 'field_asset_image');
  if (!empty($image[0]['uri'])) {
    $vars['media_field'] = field_view_value(
      'asset',
      $vars['asset'],
      'field_asset_image',
      $image[0],
      array(
        'type' => 'image',
        'settings' => array(
          'image_style' => 'asset_image_widget_search',
          'image_link' => '',
        ),
      )
    );
  }

  $description = field_get_items('asset', $vars['asset'], 'field_asset_image_description');
  if (!empty($description[0]['value'])) {
    $vars['short_description'] = field_view_value(
      'asset',
      $vars['asset'],
      'field_asset_image_description',
      $description[0],
      array(
        'type' => 'text_trimmed',
        'settings' => array(
          'trim_length' => '120',
        ),
      )
    );
  }

  // @todo: change wrapper for copyright in template.
  $copyright = field_get_items('asset', $vars['asset'], 'field_asset_image_copyright');
  if (!empty($copyright[0]['value'])) {
    $vars['short_copyright'] = field_view_value(
      'asset',
      $vars['asset'],
      'field_asset_image_copyright',
      $copyright[0],
      array(
        'type' => 'text_trimmed',
        'settings' => array(
          'trim_length' => '30',
        ),
      )
    );
  }
}

/**
 * Preprocess variables for asset--image--widget-search.tpl.php.
 *
 * @see asset--image--widget-search.tpl.php
 */
function template_preprocess_asset__video__widget_search(&$vars) {
  // Listing content.
  $video = field_get_items('asset', $vars['asset'], 'field_asset_video_file');
  if (!empty($video[0]['snapshot'])) {
    $vars['media_field'] = field_view_value(
      'asset',
      $vars['asset'],
      'field_asset_video_file',
      $video[0],
      array(
        'type' => 'emvideo_snapshot',
        'settings' => array(
          'width' => '100',
        ),
      )
    );
  }

  $description = field_get_items('asset', $vars['asset'], 'field_asset_video_desc');
  if (!empty($description[0]['value'])) {
    $vars['short_description'] = field_view_value(
      'asset',
      $vars['asset'],
      'field_asset_video_desc',
      $description[0],
      array(
        'type' => 'text_trimmed',
        'settings' => array(
          'trim_length' => '140',
        ),
      )
    );
  }
}

/**
 * Preprocess variables for asset--image--widget-search.tpl.php.
 *
 * @see asset--image--widget-search.tpl.php
 */
function template_preprocess_asset__audio__widget_search(&$vars) {
  $audio = field_get_items('asset', $vars['asset'], 'field_asset_audio');
  if (!empty($audio[0]['fid']) && !empty($audio[0]['description'])) {
    $vars['short_description'] = truncate_utf8($audio[0]['description'], '140');
  }
}

/**
 * Preprocess variables for asset--image--widget-search.tpl.php.
 *
 * @see asset--image--widget-search.tpl.php
 */
function template_preprocess_asset__document__widget_search(&$vars) {
  $description = field_get_items('asset', $vars['asset'], 'field_asset_document_desc');
  if (!empty($description[0]['value'])) {
    $vars['short_description'] = field_view_value(
      'asset',
      $vars['asset'],
      'field_asset_document_desc',
      $description[0],
      array(
        'type' => 'text_trimmed',
        'settings' => array(
          'trim_length' => '140',
        ),
      )
    );
  }
}

/**
 * Preprocess variables for asset--image--widget-search.tpl.php.
 *
 * @see asset--image--widget-search.tpl.php
 */
function template_preprocess_asset__free_html__widget_search(&$vars) {
}

/**
 * Preprocess variables for asset--image--widget-search.tpl.php.
 *
 * @see asset--image--widget-search.tpl.php
 */
function template_preprocess_asset__gallery__widget_search(&$vars) {
  // Render first element.
  $image_assets = field_get_items('asset', $vars['asset'], 'field_asset_gallery_images');
  if (!empty($image_assets[0]['target_id']) && ($asset = asset_load($image_assets[0]['target_id']))) {
    $image = field_get_items('asset', $asset, 'field_asset_image');
    if (!empty($image[0]['uri'])) {
      $vars['media_field'] = field_view_value(
        'asset',
        $asset,
        'field_asset_image',
        $image[0],
        array(
          'type' => 'image',
          'settings' => array(
            'image_style' => 'asset_image_widget_search',
            'image_link' => '',
          ),
        )
      );
    }
  }

  $description = field_get_items('asset', $vars['asset'], 'field_asset_gallery_desc');
  if (!empty($description[0]['value'])) {
    $vars['short_description'] = field_view_value(
      'asset',
      $vars['asset'],
      'field_asset_gallery_desc',
      $description[0],
      array(
        'type' => 'text_trimmed',
        'settings' => array(
          'trim_length' => '140',
        ),
      )
    );
  }
}

/**
 * Preprocess variables for asset-widget-asset-form-page.tpl.php.
 * @see asset-widget-asset-form-page.tpl.php
 */
function template_preprocess_asset_widget_asset_form_page(&$vars) {
  $vars['title'] = drupal_get_title();
  $vars['messages'] = $vars['page']['#show_messages'] ? theme('status_messages') : '';
}

/**
 * Return html for asset view mode switch block.
 */
function theme_asset_widget_view_mode_switch_block(&$vars) {
  $output = '';

  if (!empty($vars['asset']->type)) {
    if (($view_modes = _assets_get_wysiwyg_modes($vars['asset']->type)) && is_array($view_modes)) {
      $view_modes = array_keys($view_modes);

      foreach ($view_modes as $key => &$view_mode) {
        $classes = array("view-$view_mode");
        if ($key == 0) {
          $classes[] = 'active';
        }

        $classes = implode(' ', $classes);
        $view_mode = '<li class="' . $classes . '"><strong>' . $view_mode . '</strong></li>';
      }

      $output = '<ul>' . implode('', $view_modes) . '</ul>';

      // Add arrows.
      if (count($view_modes) > 1) {
        $output = '<span class="low"></span>' . $output . '<span class="high"></span>';
      }

      // Add wrapper.
      $output = '<div class="size sizes">' . $output . '</div>';
    };
  }

  return $output;
}
