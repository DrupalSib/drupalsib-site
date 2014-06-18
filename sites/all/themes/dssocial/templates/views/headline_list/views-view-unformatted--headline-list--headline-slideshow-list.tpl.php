<?php
/**
 * @file
 * views-view-unformatted--headline-list--headline-slideshow-list.tpl.php
 */
?>
<div class="slidebar-box-main slider has-slider-dots">
  <div class="slidecont slide-view">
<?php foreach ($rows as $id => $row): ?>
  <div class="<?php print $classes_array[$id]; ?>">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
  </div>
</div>
