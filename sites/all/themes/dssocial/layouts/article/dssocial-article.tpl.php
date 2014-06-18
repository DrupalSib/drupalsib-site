<?php
/**
 * @file
 * Template for a 2 column panel layout.
 *
 * This template provides a two column panel display layout, with
 * each column roughly equal in width.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['left']: Content in the left column.
 *   - $content['right']: Content in the right column.
 */
?>
<?php if (!empty($content['top'])): ?>
  <div id="ds_author">
    <div id="ds_author_social">
      <?php print $content['top']; ?>
    </div>
  </div>
<?php endif; ?>
<div id="ds_article">
  <?php if (!empty($content['left'])): ?>
    <?php print $content['left']; ?>
    <?php if (!empty($content['right'])): ?>
      <div id="ds_article_right">
        <?php print $content['right']; ?>
      </div>
    <?php endif; ?>
  <?php endif; ?>
  <?php if (!empty($content['comment_form']) || !empty($content['posted_comments'])): ?>
    <div id="ds_comment_wrapper">
      <?php if (!empty($content['comment_form'])): ?>
        <?php print $content['comment_form']; ?>
      <?php endif; ?>
      <?php if (!empty($content['posted_comments'])): ?>
        <div id="ds_comment_list">
          <?php print $content['posted_comments']; ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
</div>
