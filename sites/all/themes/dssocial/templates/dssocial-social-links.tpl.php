<?php
/**
 * @file
 * Social button.
 */
?>
<?php if (!empty($buttons)): ?>
  <div class ="custom-rate-widget">
  <?php foreach ($buttons as $button): ?>
      <ul>
        <li>
          <?php print $button; ?>
        </li>
      </ul>
  <?php endforeach; ?>
  </div>

<?php endif; ?>
