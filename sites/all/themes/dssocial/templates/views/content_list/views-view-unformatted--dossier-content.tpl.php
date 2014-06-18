<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 */
?>
<?php if (!empty($rows)): ?>
  <?php $n = count($rows); if ($n != 0): ?>
    <div class="ds_search_content">
      <div class="ds_search_results">
        <div class="ds_item_list">
          <ul>
            <?php $count = 0; ?>
            <?php foreach ($rows as $id => $row): ?>
              <li>
                <?php print $row; ?>
                <?php $count++; ?>
              </li>
              <?php if (($count % 3 == 0) && $count != $n): ?>
                </ul></div><div class="ds_item_list"><ul>
              <?php endif; ?>
           <?php endforeach; ?>
          </ul>
        </div>
      </div>
    </div>
  <?php endif; ?>
<?php endif; ?>
