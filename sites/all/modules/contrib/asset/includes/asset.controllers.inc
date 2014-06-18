<?php
/**
 * @file
 * Provides a controller classes for Asset and related entities
 */

/**
 * Use a separate class for assets so we can specify some defaults.
 */
class Asset extends Entity {

  public $type;
  public $title;
  public $created;
  public $changed;
  public $uid;
  public $in_editor = FALSE;

  /**
   * Basic constructor.
   */
  public function __construct($values = array()) {
    if (isset($values['user'])) {
      $values['uid'] = $values['user']->uid;
      unset($values['user']);
    }
    if (isset($values['type']) && is_object($values['type'])) {
      $values['type'] = $values['type']->type;
    }

    parent::__construct($values, 'asset');
    if (!isset($this->uid)) {
      $this->uid = $GLOBALS['user']->uid;
    }
    if (!isset($this->created)) {
      $this->created = REQUEST_TIME;
    }
  }

  /**
   * Defines the entity label if the 'entity_class_label' callback is used.
   */
  protected function defaultLabel() {
    if (!empty($this->title)) {
      return $this->title;
    }
    $bundle_key = $this->entityInfo['entity keys']['bundle'];
    return $this->entityInfo['bundles'][$this->$bundle_key]['label'];
  }

  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'admin/content/assets/view/' . $this->identifier());
  }

  /**
   * Builds a structured array representing the entity's content.
   */
  public function buildContent($view_mode = 'full', $langcode = NULL) {
    $build = parent::buildContent($view_mode, $langcode);
    $build['#theme_wrappers'][] = 'asset_wrapper';
    return $build;
  }
}

/**
 * UI controller for Asset.
 */
class AssetsUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    unset($items[$this->path . '/add']);
    return $items;
  }

  public function hook_forms() {
    // The overview and the operation form are implemented by the controller,
    // the callback and validation + submit handlers just invoke the controller.
    $forms[$this->entityType . '_overview_form'] = array(
      'callback' => 'entity_ui_overview_form',
      'wrapper_callback' => 'entity_ui_form_defaults',
    );
    $forms[$this->entityType . '_operation_form'] = array(
      'callback' => 'entity_ui_operation_form',
      'wrapper_callback' => 'entity_ui_form_defaults',
    );

    if (!(count($this->entityInfo['bundles']) == 1 && isset($this->entityInfo['bundles'][$this->entityType]))) {
      foreach ($this->entityInfo['bundles'] as $bundle => $bundle_info) {
        $forms[$this->entityType . '_edit_' . $bundle . '_form']['callback'] = 'asset_base_form';
      }
    }
    return $forms;
  }
}


class AssetViewsController extends EntityDefaultViewsController  {

  /**
   * Alternative for hook_views_data().
   */
  public function views_data() {
    $data = parent::views_data();
    $table = $this->info['base table'];

    $data[$table]['aid'] = array(
      'title' => t('Aid'),
      'help' => t('The asset ID.'),
      'field' => array(
        'handler' => 'asset_views_handler_field_asset',
        'click sortable' => TRUE,
      ),
      'argument' => array(
        'handler' => 'asset_views_handler_argument_asset_aid',
        'name field' => 'title',
        'numeric' => TRUE,
        'validate type' => 'aid',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    );

    $data[$table]['title'] = array(
      'title' => t('Title'),
      'help' => t('The asset title.'),
      'field' => array(
        'handler' => 'asset_views_handler_field_asset',
        'click sortable' => TRUE,
        'link_to_asset default' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    );

    // Set proper filter handler to allow autocomplete on field.
    $data[$table]['uid']['filter']['handler'] = 'views_handler_filter_user_name';
    $data[$table]['edit_asset'] = array(
      'field' => array(
        'title' => t('Edit link'),
        'help' => t('Provide a simple link to edit the asset.'),
        'handler' => 'asset_views_handler_field_asset_link_edit',
      ),
    );

    $data[$table]['delete_asset'] = array(
      'field' => array(
        'title' => t('Delete link'),
        'help' => t('Provide a simple link to delete the asset.'),
        'handler' => 'asset_views_handler_field_asset_link_delete',
      ),
    );

    $data[$table]['insert_asset'] = array(
      'field' => array(
        'title' => t('Insert button'),
        'help' => t('Provide a button for assets library.'),
        'handler' => 'asset_views_handler_field_asset_link_insert',
      ),
    );

    return $data;
  }
}

/**
 * Use a separate class for asset types so we can specify some defaults.
 */
class AssetType extends Entity {

  public $type;
  public $name;
  public $icon;
  public $description;
  public $help;
  public $weight = 0;

  public function __construct($values = array()) {
    parent::__construct($values, 'asset_type');
  }

  /**
   * Returns whether the asset type is locked, thus may not be deleted or renamed.
   *
   * Asset types provided in code are automatically treated as locked,
   * as well as any fixed asset type.
   */
  public function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
  }

  /**
   * Delete function.
   *
   * We have to override this method just to invoke the entity_defaults_rebuild,
   * in case when no existent types were reverted
   *
   * @param $ids
   * @param DatabaseTransaction | null $transaction
   */
  public function delete() {
    parent::delete();
    entity_defaults_rebuild(array($this->entityType));
  }
}
