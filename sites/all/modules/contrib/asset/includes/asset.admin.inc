<?php
/**
 * @file
 * Asset admin page callbacks.
 */

/**
 * Generates the asset type editing form.
 */
function asset_type_form($form, &$form_state, $asset_type, $op = 'edit') {
  if ($op == 'clone') {
    $asset_type->name .= ' (cloned)';
    $asset_type->type .= '_clone';
  }

  $form['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textfield',
    '#description' => t('The human-readable name of this asset type. This text will be displayed as part of the list on the <em>Add new asset</em> page. It is recommended that this name begin with a capital letter and contain only letters, numbers, and spaces. This name must be unique.'),
    '#required' => TRUE,
    '#default_value' => $asset_type->name,
  );

  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($asset_type->type) ? $asset_type->type : '',
    '#disabled' => $asset_type->isLocked(),
    '#machine_name' => array(
      'exists' => 'assets_get_types',
      'source' => array('name'),
    ),
    '#description' => t('A unique machine-readable name for this asset type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textarea',
    '#default_value' => $asset_type->description,
    '#description' => t('Describe this asset type. The text will be displayed on the <em>Add new asset</em> page.'),
  );

  $form['help']  = array(
    '#type' => 'textarea',
    '#title' => t('Explanation or submission guidelines'),
    '#default_value' => $asset_type->help,
    '#description' => t('This text will be displayed at the top of the page when creating or editing asset of this type.'),
  );

  $form['icons'] = array(
    '#type' => 'fieldset',
    '#title' => t('Icon settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $icons_options = array('none' => t('No icon'));
  $module_icons = _assets_get_icons();
  if (!empty($module_icons)) {
    $icons_options = $icons_options + $module_icons;
  }

  $form['icons']['icon'] = array(
    '#type' => 'radios',
    '#default_value' => $asset_type->icon ? $asset_type->icon : reset(array_keys($icons_options)),
    '#options' => $icons_options,
    '#title' => t('Button icon'),
  );

  $form['weight'] = array(
    '#title' => t('Weight'),
    '#type' => 'weight',
    '#default_value' => $asset_type->weight,
    '#weight' => 50,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save asset type'),
    '#weight' => 40,
  );

  if (!$asset_type->isLocked() && $op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete asset type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('asset_type_form_submit_delete'),
    );
  }

  return $form;
}

/**
 * Form API submit callback for the asset type form.
 */
function asset_type_form_submit($form, &$form_state) {
  $asset_type = entity_ui_form_submit_build_entity($form, $form_state);
  $asset_type->save();
  $form_state['redirect'] = 'admin/structure/assets';
}

/**
 * Form API submit callback for the delete button.
 */
function asset_type_form_submit_delete(&$form, &$form_state) {
  if (isset($_GET['destination'])) {
    $form_state['redirect'] = array(
      'admin/structure/assets/manage/' . $form_state['asset_type']->type . '/delete',
      array(
        'query' => array(
          'destination' => $_GET['destination'],
        ),
      ),
    );

    unset($_GET['destination']);
  }
  else {
    $form_state['redirect'] = 'admin/structure/assets/manage/' . $form_state['asset_type']->type . '/delete';
  }
}

/**
 * Base form builder.
 */
function asset_base_form($form, &$form_state, $asset, $op = 'edit') {
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#required' => TRUE,
    '#default_value' => $asset->title,
    '#maxlength' => 255,
    '#weight' => -5,
    '#description' => t('Title of asset'),
  );

  field_attach_form('asset', $asset, $form, $form_state);
  $form['#submit'] = array('asset_base_form_submit');

  unset($form['#validate']);

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 5,
  );

  if (!empty($asset->aid) && user_access('administer assets')) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#weight' => 15,
      '#submit' => array('asset_base_form_submit_delete'),
    );
  }

  return $form;
}

/**
 * Form API submit callback for the asset form.
 */
function asset_base_form_submit($form, &$form_state) {
  $asset = entity_ui_form_submit_build_entity($form, $form_state);
  $asset->save();
  $form_state['asset'] = $asset;
  $form_state['redirect'] = 'admin/content/assets';
}

/**
 * Form API submit callback for the delete button.
 */
function asset_base_form_submit_delete(&$form, &$form_state) {
  if (isset($_GET['destination'])) {
    $form_state['redirect'] = array(
      'admin/content/assets/manage/' . $form_state['asset']->aid . '/delete',
      array(
        'query' => array(
          'destination' => $_GET['destination'],
        ),
      ),
    );

    unset($_GET['destination']);
  }
  else {
    $form_state['redirect'] = 'admin/content/assets/manage/' . $form_state['asset']->aid . '/delete';
  }
}

/**
 * Page callback for asset add page.
 */
function assets_add_page() {
  $item = menu_get_item();
  $content = system_admin_menu_block($item);

  if (isset($_GET['destination'])) {
    $destination = array('destination' => $_GET['destination']);

    foreach ($content as $mlid => $item) {
      $content[$mlid]['localized_options']['query'] = $destination;
    }
  }

  // Bypass the asset/add listing if only one content type is available.
  if (count($content) == 1) {
    $item = array_shift($content);
    drupal_goto($item['href']);
  }

  return theme('node_add_list', array('content' => $content));
}

/**
 * Returns an asset submission form.
 */
function assets_add($type) {
  $asset = new Asset(array('type' => $type));
  $form = entity_ui_get_form('asset', $asset, 'add');

  // Due to dummy  usage of entity->label instead of entity_label() in entity API.
  $label = drupal_strtolower(entity_label('asset', $asset));
  drupal_set_title(t("Add $label"), PASS_THROUGH);

  return $form;
}

/**
 * Adds a fields for an asset tag values to the given form.
 */
function _assets_wysiwyg_fields(&$form, $asset, $options) {
  $entity_info = $asset->entityInfo();
  $align = isset($options['align']) && in_array($options['align'], array('left', 'right', ''), TRUE)
    ? $options['align']
    : '';
  $mode = isset($options['mode']) ? $options['mode'] : '';

  $modes = array();
  $modes_count = 0;

  // To get the human titles.
  $view_modes = $entity_info['view modes'];
  $wysiwyg_modes = _assets_get_wysiwyg_modes($asset->type);

  if (!empty($wysiwyg_modes)) {
    foreach ($wysiwyg_modes as $view_mode_name) {
      $modes[$view_mode_name] = $view_modes[$view_mode_name]['label'];
    }

    $modes_count = count($modes);

    if (!array_key_exists($mode, $modes) && $modes_count) {
      $mode = reset(array_keys($modes));
    }

    if ($modes_count > 1) {
      $form['view_mode'] = array(
        '#type' => 'select',
        '#title' => t('Display mode'),
        '#default_value' => $mode,
        '#options' => $modes,
        '#weight' => 29,
      );
    }
    else {
      $form['view_mode'] = array(
        '#type' => 'value',
        '#value' => $mode,
      );
    }
  }

  // A convention that default view mode shouldn't have align options.
  if (1 >= $modes_count && $mode === ASSET_DEFAULT_MODE) {
    $form['align'] = array(
      '#type' => 'value',
      '#value' => '',
    );
  }
  else {
    $form['align'] = array(
      '#type' => 'radios',
      '#title_display' => 'before',
      '#title' => t('Alignment'),
      '#default_value' => $align,
      '#options' => array(
        '' => t('None'),
        'left' => t('Left'),
        'right' => t('Right'),
      ),
      '#weight' => 30,
    );

    if ($modes_count > 1) {
      $form['align']['#states'] = array(
        'visible' => array(
          ':input[name=view_mode]' => array('value' => 'small'),
        ),
      );
    }
  }

  return $form;
}

/**
 * Page callback for wysiwyg form.
 */
function assets_wysiwyg_form($form, &$form_state, $op, $asset, $mode = ASSET_DEFAULT_MODE, $align = '') {
  if ($op == 'add') {
    $type = drupal_substr($asset, 6);
    $asset = new Asset(array('type' => $type));
  }

  $form_state['entity_type'] = 'asset';
  $form_state['op'] = $op;
  $form_state['asset'] = $asset;
  $form_state['build_info']['base_form_id'] = 'asset_base_form';

  $form = asset_base_form($form, $form_state, $asset, $op);
  $form['#submit'][] = 'asset_base_form_submit';

  if ($op == 'add') {
    $form['#submit'][] = 'assets_wysiwyg_add_form_submit';
  }
  else {
    $form['#submit'][] = 'assets_wysiwyg_form_submit';
  }

  _assets_wysiwyg_fields($form, $asset, array('mode' => $mode, 'align' => $align));

  unset($form['actions']['delete']);

  return $form;
}

/**
 * Page callback for asset override form in wysiwyg.
 */
function assets_override_form($form, &$form_state) {
  $form = array();

  if (isset($_REQUEST['tag']) && !empty($_REQUEST['tag'])) {
    $tag = $_REQUEST['tag'];
    $matches = assets_filter_get_matches($tag);

    if (!empty($matches)) {
      $match = reset($matches);
      $aid = (int) $match[2];
      $params = $match[3];
      $asset = asset_load($aid);
      $form_state['asset'] = $asset;
      $form_state['entity_type'] = 'asset';

      $form_state['build_info']['base_form_id'] = 'asset_base_form';
      $params = '{' . $params . '}';
      $options = json_decode($params, TRUE);

      if (is_array($options)) {
        $values = array_diff_key($options, array('mode' => 1, 'align' => 1));
        foreach ($values as $name => $value) {
          _assets_set_field_value($asset, $name, $value);
        }
      }
      else {
        $options = array();
      }
      field_attach_form('asset', $asset, $form, $form_state);

      _assets_clean_fields($form, $options);
      _assets_wysiwyg_fields($form, $asset, $options);

      $form['actions'] = array('#type' => 'actions');
      $form['actions']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Override'),
        '#weight' => 5,

      );

      $form['#submit'][] = 'assets_override_form_submit';
    }
  }

  // @todo: Add validation handlers.
  return $form;
}

/**
 * Helper function.
 */
function _assets_clean_fields(&$form, $options = array()) {
  $containers = element_children($form);
  $supported_types = _assets_get_supported_field_types();

  foreach ($containers as $key) {
    if (isset($form[$key]) && $form[$key]) {
      $elements = $form[$key][$form[$key]['#language']];
      $multiple = isset($elements['#cardinality']) && ($elements['#cardinality'] > 1 || $elements['#cardinality']) == FIELD_CARDINALITY_UNLIMITED;
      $children = element_children($elements);

      if (!empty($children)) {
        foreach ($children as $delta) {
          if (isset($elements[$delta]) && $elements[$delta]) {
            $info = field_info_field($key);

            if (!empty($info) && in_array($info['type'], $supported_types)) {
              unset($field);

              switch ($info['type']) {
                case 'text':
                case 'text_long':
                  $field = &$form[$key][$form[$key]['#language']][$delta];
                  if ($multiple) {
                    $field = &$form[$key][$form[$key]['#language']][$delta]['value'];
                  }
                  break;
              }

              if (isset($field) && !$field['#required']) {
                if (isset($options[$key])) {
                  $value = (array) $options[$key];

                  if (!empty($value[$delta])) {
                    continue;
                  }
                }

                $field['#default_value'] = '';
                continue;
              }
            }

            unset($form[$key]);
          }
        }
      }
      else {
        $info = field_info_field($key);
        if (!empty($info) && in_array($info['type'], $supported_types)) {
          unset($field);

          switch ($info['type']) {
            case 'text':
              $field = &$form[$key][$form[$key]['#language']];
              if ($multiple) {
                $field = &$form[$key][$form[$key]['#language']]['value'];
              }
              break;
          }

          if (isset($field) && !$field['#required']) {
            if (isset($options[$key])) {
              $value = (array) $options[$key];

              if (!empty($value[$delta])) {
                continue;
              }
            }

            $field['#default_value'] = '';
            continue;
          }
        }

        unset($form[$key]);
      }
    }
  }
}

/**
 * Custom submit handler.
 */
function assets_override_form_submit(&$form, &$form_state) {
  $values = $form_state['values'];
  $view_mode = isset($values['view_mode']) ? $values['view_mode'] : ASSET_DEFAULT_MODE;
  $alignment = isset($values['align']) ? $values['align'] : '';
  $asset = entity_ui_form_submit_build_entity($form, $form_state);
  $placeholder = assets_get_placeholder($asset, array('mode' => $view_mode, 'align' => $alignment));
  $placeholder = addslashes($placeholder);
  $placeholder = str_replace("\r\n", '\n', $placeholder);

  $js = 'var CKEDITOR = parent.CKEDITOR;
    var dialog =  CKEDITOR.dialog.getCurrent();
    var outdated = dialog._outdatedAssetEl;
    if (outdated) {
      var tag_id = outdated.data(\'asset-cid\');
      dialog._.editor.plugins.asset.replaceAsset(tag_id, \'' . $placeholder . '\' );
    }
    dialog.hide();';

  echo '<script>' . $js . '</script>';
  drupal_exit();
}

/**
 * Custom submit handler.
 */
function assets_wysiwyg_add_form_submit(&$form, &$form_state) {
  $asset = $form_state['asset'];
  $values = $form_state['values'];
  $view_mode = isset($values['view_mode']) ? $values['view_mode'] : ASSET_DEFAULT_MODE;
  $alignment = isset($values['align']) ? $values['align'] : '';

  $placeholder = assets_get_placeholder($asset, array('mode' => $view_mode, 'align' => $alignment));
  $placeholder = addslashes($placeholder);
  $placeholder = str_replace("\r\n", '\n', $placeholder);

  $js = 'var CKEDITOR = parent.CKEDITOR;
    var dialog = CKEDITOR.dialog.getCurrent();
    var newHtml = dialog._.editor.plugins.asset.Assets.getContentByTag(\'' . $placeholder . '\');
    //var newHtml = dialog.definition.Assets.getContentByTag(\'' . $placeholder . '\');
    if (newHtml) {
      var element = CKEDITOR.dom.element.createFromHtml(newHtml);
      element.setAttribute(\'contentEditable\', \'false\');   //Hello, Chrome
      dialog._.editor.insertElement(element);
      if (CKEDITOR.env.gecko && newHtml.search(/<object /i) > 0) {
        var wysiwyg = dialog._.editor.getMode();
        wysiwyg.loadData(wysiwyg.getData());
      }
    }
    dialog.hide();';

  echo '<script>' . $js . '</script>';
  drupal_exit();
}

/**
 * Custom submit handler.
 */
function assets_wysiwyg_form_submit(&$form, &$form_state) {
  $asset     = $form_state['asset'];
  $values    = $form_state['values'];
  $view_mode = isset($values['view_mode']) ? $values['view_mode'] : ASSET_DEFAULT_MODE;
  $alignment = isset($values['align']) ? $values['align'] : '';

  $placeholder = assets_get_placeholder($asset, array('mode' => $view_mode, 'align' => $alignment));
  $placeholder = addslashes($placeholder);
  $placeholder = str_replace("\r\n", '\n', $placeholder);

  $js = 'var CKEDITOR = parent.CKEDITOR;
    var dialog =  CKEDITOR.dialog.getCurrent();
    var outdated = dialog._outdatedAssetEl;
    if (outdated) {
      var tag_id = outdated.data(\'asset-cid\');
      dialog._.editor.plugins.asset.replaceAsset(tag_id, \'' . $placeholder . '\' );
    }
    dialog.hide();';

  echo '<script>' . $js . '</script>';
  drupal_exit();
}

/**
 * Page callback to get html for asset preview in wysiwyg.
 */
function assets_get_content() {
  $content = '';

  if (isset($_REQUEST['tag']) && !empty($_REQUEST['tag'])) {
    $tag = $_REQUEST['tag'];
    $matches = assets_filter_get_matches($tag);
    if (!empty($matches)) {
      $match = reset($matches);
      $asset = asset_load($match[2]);
      $content .= assets_render_by_tag($asset, $match[3], TRUE);
    }
  }

  print $content;
  drupal_exit();
}

/**
 * Page callback, return html of full asset.
 */
function asset_get_full_content() {
  $content = '';

  if (isset($_REQUEST['tag']) && !empty($_REQUEST['tag'])) {
    $tag = $_REQUEST['tag'];
    $matches = assets_filter_get_matches($tag);

    if (!empty($matches)) {
      $match = reset($matches);
      $asset = asset_load($match[2]);
      $content .= assets_render_by_tag($asset, $match[3], FALSE);
    }
  }

  return $content;
}

/**
 * Page callback, return html of asset by wysiwyg view mode.
 */
function _asset_get_tag($tag_id, $view_mode = NULL, $align = NULL) {
  $output = '';
  $placeholder = '';

  $tags = explode(':', $tag_id);
  $asset = !empty($tags[0]) ? asset_load($tags[0]) : NULL;

  if ($asset) {
    if (empty($view_mode) || ($view_mode == 'default')) {
      $view_modes = variable_get('assets_default_wysiwyg_modes', array());

      if (!empty($view_modes[$asset->type])) {
        $view_mode = $view_modes[$asset->type];
      }
      else {
        $view_mode = ASSET_DEFAULT_MODE;
      }
    }

    $asset->in_editor = TRUE;
    $placeholder = assets_get_placeholder(
      $asset,
      array(
        'mode' => $view_mode,
        'align' => $align,
      )
    );
    $placeholder = str_replace("\r\n", '\n', $placeholder);

    $asset_content = $asset->view($view_mode);
    $output = render($asset_content);
  }

  print drupal_json_encode(
    array(
      'tag' => $placeholder,
      'content' => $output,
    )
  );

  drupal_exit();
}

/**
 * Page callback to get tooltip content.
 */
function asset_tooltip_content($asset, $view_mode) {
  return asset_view_asset($asset, $view_mode);
}

/**
 * Page callback to get asset html.
 */
function asset_view_asset($asset, $view_mode = ASSET_DEFAULT_MODE) {
  $output = $asset->view($view_mode);
  return render($output);
}
