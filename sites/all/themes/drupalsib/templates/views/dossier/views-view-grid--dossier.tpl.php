<?php
/**
 * 
 */
?>
<div class="ds_search_results">
  <?php foreach ($rows as $row_number => $columns): ?>
  <div class="ds_item_list">  
    <ul>
      <?php foreach ($columns as $column_number => $item): ?>
        <li class>
          <?php print $item; ?>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
  <?php endforeach; ?>
</div>