<?php
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="ds_block_search_results">
  <div class="item_list">
    <ul>
      <?php foreach ($rows as $id => $row): ?>
        <li><?php print $row; ?></li>
      <?php endforeach; ?>
    </ul>
  </div>
</div>
