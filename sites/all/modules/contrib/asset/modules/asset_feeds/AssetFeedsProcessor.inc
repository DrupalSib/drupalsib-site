<?php
/**
 * @file
 * Class definition of AssetFeedsProcessor.
 */

/**
 * Creates assets from feed items.
 */
class AssetFeedsProcessor extends FeedsProcessor {

  /**
   * Define entity type.
   */
  public function entityType() {
    return 'asset';
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Assets');

    return $info;
  }

  /**
   * Creates a new asset in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {
    $asset = new Asset(array('type' => $this->config['asset_type']));
    $asset->changed = REQUEST_TIME;
    $asset->created = REQUEST_TIME;
    $asset->uid = $this->config['author'];

    return $asset;
  }

  /**
   * Loads an existing asset.
   *
   * If the update existing method is not FEEDS_UPDATE_EXISTING, only the asset
   * table will be loaded for better performance.
   *
   */
  protected function entityLoad(FeedsSource $source, $aid) {
    if ($this->config['update_existing'] == FEEDS_UPDATE_EXISTING) {
      $asset = asset_load($aid, TRUE);
    }
    else {
      // We're replacing the existing entity. Only save the absolutely necessary.
      $asset = new Asset(array(
        'aid' => $aid,
        'uid' => $this->config['author'],
      ));
      $asset = db_query("SELECT created, nid, type FROM {asset} WHERE aid = :aid", array(':aid' => $aid))->fetchObject();
      $asset->uid = $this->config['author'];
    }

    return $asset;
  }

  /**
   * Save an asset.
   */
  public function entitySave($entity) {
    entity_save('asset', $entity);
  }

  /**
   * Delete a series of assets.
   */
  protected function entityDeleteMultiple($aids) {
    entity_delete_multiple('asset', $aids);
  }

  /**
   * Implement expire().
   *
   */
  public function expire($time = NULL) {
    if ($time === NULL) {
      $time = $this->expiryTime();
    }

    if ($time == FEEDS_EXPIRE_NEVER) {
      return;
    }

    $count = $this->getLimit();

    $assets = db_query_range("SELECT a.aid FROM {asset} a JOIN {feeds_item} fi ON fi.entity_type = 'asset' AND a.aid = fi.entity_id WHERE fi.id = :id AND a.created < :created", 0, $count, array(':id' => $this->id, ':created' => REQUEST_TIME - $time));
    $aids = array();
    foreach ($assets as $asset) {
      $aids[$asset->aid] = $asset->aid;
    }

    $this->entityDeleteMultiple($aids);
    if (db_query_range("SELECT 1 FROM {asset} a JOIN {feeds_item} fi ON fi.entity_type = 'asset' AND a.aid = fi.entity_id WHERE fi.id = :id AND a.created < :created", 0, 1, array(':id' => $this->id, ':created' => REQUEST_TIME - $time))->fetchField()) {
      return FEEDS_BATCH_ACTIVE;
    }

    return FEEDS_BATCH_COMPLETE;
  }

  /**
   * Return expiry time.
   */
  public function expiryTime() {
    return $this->config['expire'];
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    $types = assets_get_types();
    $type = '';

    if (!empty($types)) {
      $type = key($types);
    }

    return array(
      'asset_type' => $type,
      'expire' => FEEDS_EXPIRE_NEVER,
      'author' => 0,
    ) + parent::configDefaults();
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $types = asset_type_get_names();
    array_walk($types, 'check_plain');

    $form = parent::configForm($form_state);
    $form['asset_type'] = array(
      '#type' => 'select',
      '#title' => t('Asset type'),
      '#description' => t('Select the content type for the assets to be created. <strong>Note:</strong> Users with "import !feed_id feeds" permissions will be able to <strong>import</strong> assets of the type selected here regardless of the asset level permissions. Further, users with "clear !feed_id permissions" will be able to <strong>delete</strong> imported assets regardless of their asset level permissions.', array('!feed_id' => $this->id)),
      '#options' => $types,
      '#default_value' => $this->config['asset_type'],
    );

    $author = user_load($this->config['author']);
    $form['author'] = array(
      '#type' => 'textfield',
      '#title' => t('Author'),
      '#description' => t('Select the author of the assets to be created - leave empty to assign "anonymous".'),
      '#autocomplete_path' => 'user/autocomplete',
      '#default_value' => empty($author->name) ?  'anonymous' : check_plain($author->name),
    );

    $period = drupal_map_assoc(array(FEEDS_EXPIRE_NEVER, 3600, 10800, 21600, 43200, 86400, 259200, 604800, 2592000, 2592000 * 3, 2592000 * 6, 31536000), 'feeds_format_expire');
    $form['expire'] = array(
      '#type' => 'select',
      '#title' => t('Expire assets'),
      '#options' => $period,
      '#description' => t("Select after how much time assets should be deleted. The asset's published date will be used for determining the asset's age, see Mapping settings."),
      '#default_value' => $this->config['expire'],
    );

    $form['update_existing']['#options'] = array(
      FEEDS_SKIP_EXISTING => 'Do not update existing assets',
      FEEDS_REPLACE_EXISTING => 'Replace existing assets',
      FEEDS_UPDATE_EXISTING => 'Update existing assets (slower than replacing them)',
    );

    return $form;
  }

  /**
   * Override parent::configFormValidate().
   */
  public function configFormValidate(&$values) {
    if ($author = user_load_by_name($values['author'])) {
      $values['author'] = $author->uid;
    }
    else {
      $values['author'] = 0;
    }
  }

  /**
   * Reschedule if expiry time changes.
   */
  public function configFormSubmit(&$values) {
    if ($this->config['expire'] != $values['expire']) {
      feeds_reschedule($this->id);
    }
    parent::configFormSubmit($values);
  }

  /**
   * Override setTargetElement to operate on a target item that is an asset.
   */
  public function setTargetElement(FeedsSource $source, $target_asset, $target_element, $value) {
    switch ($target_element) {
      case 'created':
        $target_asset->created = feeds_to_unixtime($value, REQUEST_TIME);
        break;

      case 'feeds_source':
        // Get the class of the feed asset importer's fetcher and set the source
        // property. See asset_feeds_asset_update() how $asset->feeds gets stored.
        if ($id = feeds_get_importer_id($this->config['asset_type'])) {
          $class = get_class(feeds_importer($id)->fetcher);
          $target_asset->feeds[$class]['source'] = $value;
          // This effectively suppresses 'import on submission' feature.
          // See asset_feeds_asset_insert().
          $target_asset->feeds['suppress_import'] = TRUE;
        }
        break;

      default:
        parent::setTargetElement($source, $target_asset, $target_element, $value);
        break;
    }
  }

  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
    $targets = parent::getMappingTargets();

    $targets['title'] = array(
      'name' => t('Title'),
      'description' => t('The title of the asset.'),
      'optional_unique' => TRUE,
    );

    $targets['aid'] = array(
      'name' => t('Asset ID'),
      'description' => t('The aid of the asset. NOTE: use this feature with care, asset ids are usually assigned by Drupal.'),
      'optional_unique' => TRUE,
    );
    $targets['uid'] = array(
      'name' => t('User ID'),
      'description' => t('The Drupal user ID of the asset author.'),
    );
    $targets['created'] = array(
      'name' => t('Created date'),
      'description' => t('The UNIX time when an asset has been created.'),
    );

    // Let other modules expose mapping targets.
    self::loadMappers();
    feeds_alter('feeds_processor_targets', $targets, 'asset', $this->config['asset_type']);

    return $targets;
  }

  /**
   * Get aid of an existing feed item asset if available.
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($aid = parent::existingEntityId($source, $result)) {
      return $aid;
    }

    // Iterate through all unique targets and test whether they do already
    // exist in the database.
    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
      switch ($target) {
        case 'aid':
          $aid = db_query("SELECT aid FROM {asset} WHERE aid = :aid", array(':aid' => $value))->fetchField();
          break;

        case 'title':
          $aid = db_query("SELECT aid FROM {asset} WHERE title = :title", array(':title' => $value))->fetchField();
          break;

        case 'feeds_source':
          if ($id = feeds_get_importer_id($this->config['asset_type'])) {
            $aid = db_query("SELECT fs.feed_nid FROM {asset} a JOIN {feeds_source} fs ON a.aid = fs.feed_nid WHERE fs.id = :id AND fs.source = :source", array(':id' => $id, ':source' => $value))->fetchField();
          }
          break;
      }

      if ($aid) {
        // Return with the first aid found.
        return $aid;
      }
    }

    return 0;
  }
}
