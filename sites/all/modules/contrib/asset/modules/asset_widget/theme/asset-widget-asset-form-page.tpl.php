<?php
/**
 * @file
 * Template for forms inside our widget.
 */
?>
<div class="frame-page-wrapper">
  <?php if ($title): ?>
    <h1 class="page-title"><?php print $title; ?></h1>
  <?php endif; ?>
  <?php if (isset($messages)): print $messages; endif; ?>
  <?php print render($page['content']); ?>
</div>
