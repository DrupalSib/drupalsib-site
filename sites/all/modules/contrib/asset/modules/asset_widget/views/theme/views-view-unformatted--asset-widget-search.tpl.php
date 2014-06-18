<?php
/**
 * @file
 * views-view-unformatted--asset-widget-search.tpl.php
 *
 * View template for asset widget search style output.
 *
 * @ingroup views_templates
 */
?>
<span class="separator"></span>
<div class="items-wrap">
  <ul class="items">
    <?php foreach ($rows as $id => $row): ?>
      <li class="<?php print $wrapper_classes[$id]; ?>">
        <?php print $row; ?>
      </li>
    <?php endforeach; ?>
  </ul>
</div>
<span class="separator"></span>
