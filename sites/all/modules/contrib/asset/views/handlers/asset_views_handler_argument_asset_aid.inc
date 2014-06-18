<?php
/**
 * @file
 * Provide node aid argument handler.
 */

/**
 * Argument handler to accept an asset id.
 */
class asset_views_handler_argument_asset_aid extends views_handler_argument_numeric {

  /**
   * Override the behavior of title(). Get the title of the node.
   */
  function title_query() {
    $titles = array();

    $result = db_query("SELECT a.title FROM {asset} a WHERE a.aid IN (:aids)", array(':aids' => $this->value));
    foreach ($result as $asset) {
      $titles[] = check_plain($asset->title);
    }

    return $titles;
  }
}
