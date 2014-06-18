<?php
/**
 * @file
 * Asset Migrate integration.
 */

/*
 * Implements hook_migrate_api().
 *
 * We have to implement hook_migrate_api(), setting the API level to 2, for
 * our migration classes to be recognized by the Migrate module.
 */
function asset_migrate_api() {
  return array('api' => 2);
}

/**
 * Destination class implementing migration into assets.
 */
class MigrateDestinationAsset extends MigrateDestinationEntity {

  /**
   * Get key from schema.
   */
  static public function getKeySchema() {
    return array(
      'aid' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => 'ID of a destination asset',
      ),
    );
  }

  /**
   * Basic initialization.
   *
   * @param string $bundle
   *   A.k.a. the asset type (image, video, etc.) of the asset.
   * @param array $options
   *   Options applied to assets.
   */
  public function __construct($bundle, array $options = array()) {
    parent::__construct('asset', $bundle, $options);
  }

  /**
   * Returns a list of fields available to be mapped for the asset type (bundle).
   *
   * @return array
   *   Keys: machine names of the fields (to be passed to addFieldMapping)
   *   Values: Human-friendly descriptions of the fields.
   */
  public function fields() {
    $fields = array();
    // First the core (asset table) properties.
    $fields['aid'] = t('Asset: Existing asset ID');
    $fields['uid'] = t('Asset: Authored by (uid)');
    $fields['title'] = t('Asset: Title');
    $fields['created'] = t('Asset: Created timestamp');
    $fields['changed'] = t('Asset: Modified timestamp');

    // Then add in anything provided by handlers.
    $fields += migrate_handler_invoke_all('Entity', 'fields', $this->entityType, $this->bundle);
    $fields += migrate_handler_invoke_all('Asset', 'fields', $this->entityType, $this->bundle);

    return $fields;
  }

  /**
   * Delete a batch of assets at once.
   *
   * @param $aids
   *   Array of asset IDs to be deleted.
   */
  public function bulkRollback(array $aids) {
    migrate_instrument_start('asset_delete_multiple');
    $this->prepareRollback($aids);
    entity_delete_multiple('asset', $aids);
    $this->completeRollback($aids);
    migrate_instrument_stop('asset_delete_multiple');
  }

  /**
   * Import a single asset.
   *
   * @param $mapped_asset
   *   Asset object to build. Prefilled with any fields mapped in the Migration.
   * @param $row
   *   Raw source data object - passed through to prepare/complete handlers.
   * @return array
   *   Array of key fields (aid only in this case) of the asset that was saved if
   *   successful. FALSE on failure.
   *
   */
  public function import(stdClass $mapped_asset, stdClass $row) {
    $asset = new Asset(array('type' => $this->bundle));
    foreach ((array) $mapped_asset as $key => $value) {
      $asset->$key = $value;
    }

    // Updating previously-migrated content?
    $migration = Migration::currentMigration();
    if (isset($row->migrate_map_destid1)) {
      if (isset($asset->aid)) {
        if ($asset->aid != $row->migrate_map_destid1) {
          throw new MigrateException(t("Incoming aid !aid and map destination aid !destid1 don't match",
            array('!aid' => $asset->aid, '!destid1' => $row->migrate_map_destid1)));
        }
      }
      else {
        $asset->aid = $row->migrate_map_destid1;
      }
    }
    if ($migration->getSystemOfRecord() == Migration::DESTINATION) {
      if (!isset($asset->aid)) {
        throw new MigrateException(t('System-of-record is DESTINATION, but no destination aid provided'));
      }
      $old_asset = asset_load($asset->aid);
      if (!isset($asset->created)) {
        $asset->created = $old_asset->created;
      }
      if (!isset($asset->uid)) {
        $asset->uid = $old_asset->uid;
      }
    }

    if ($migration->getSystemOfRecord() == Migration::SOURCE) {
      // Apply defaults, allow standard asset prepare hooks to fire.
      // asset_object_prepare() will blow these away, so save them here and
      // stuff them in later if need be.
      if (isset($asset->created)) {
        $asset->created = MigrationBase::timestamp($asset->created);
      }
      else {
        // To keep asset_object_prepare() from choking.
        $asset->created = REQUEST_TIME;
      }
      if (isset($asset->changed)) {
        $changed = MigrationBase::timestamp($asset->changed);
      }
      if (!isset($asset->uid)) {
        global $user;
        $asset->uid = $user->uid;
      }
    }

    // Invoke migration prepare handlers.
    $this->prepare($asset, $row);


    // Trying to update an existing node.
    if ($migration->getSystemOfRecord() == Migration::DESTINATION) {
      // Incoming data overrides existing data, so only copy non-existent fields.
      foreach ($old_asset as $field => $value) {
        // An explicit NULL in the source data means to wipe to old value (i.e.,
        // don't copy it over from $old_node).
        if (property_exists($asset, $field) && $asset->$field === NULL) {
          // Ignore this field.
        }
        elseif (!isset($asset->$field)) {
          $asset->$field = $old_asset->$field;
        }
      }
    }

    if (isset($asset->aid)) {
      $updating = TRUE;
    }
    else {
      $updating = FALSE;
    }

    if (!empty($asset->title)) {
      migrate_instrument_start('asset_save');
      $asset->save();
      migrate_instrument_stop('asset_save');
    }
    else {
      throw new MigrateException(t("Asset for the article !path wasn't created as long as it doesn't have any associated title.",
        array('!path' => $row->lien)));
    }

    if (isset($asset->aid)) {
      if ($updating) {
        $this->numUpdated++;
      }
      else {
        $this->numCreated++;
      }
      $return = array($asset->aid);
    }
    else {
      $return = FALSE;
    }

    $this->complete($asset, $row);
    return $return;
  }
}
