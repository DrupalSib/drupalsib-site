<?php
/**
 * @file views-view-unformatted--headline-list--headline-tiles-list.tpl.php
 */
?>
<?php foreach ($rows as $id => $row): ?>
  <div class="<?php print $classes_array[$id]; ?>">
    <?php print $row;?>
  </div>
<?php endforeach; ?>
