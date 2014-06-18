<?php
/**
 * @file
 * Author information this theme.
 */
?>
<?php if (!empty($author_information['author_image'])): ?>
  <div class="ds_user-properties_image">
    <?php print $author_information['author_image']?>
  </div>
<?php endif; ?>
<?php if (!empty($author_information['author_name']) && !empty($author_information['author_date_publication'])): ?>
  <div class="ds_user-properties">
    <h3>
      <?php if (!empty($author_information['author_name'])): ?>
        <?php print $author_information['author_name']?>
      <?php endif; ?>
    </h3>
    <?php if (!empty($author_information['author_date_publication'])): ?>
        <span class="ds_user-properties_date">
          <?php print $author_information['author_date_publication']?>
        </span>
    <?php endif; ?>
  </div>
<?php endif; ?>
