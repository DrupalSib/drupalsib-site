<?php
/**
 * @file
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
$votes = '';
?>
<?php foreach ($choice as $chvote) : ?>
  <?php $votes += (int) $chvote['chvotes']; ?>
<?php endforeach; ?>
<div class="poll">
  <div class="poll-list-item item-with-image">
    <div class="block-content">
      <?php if (!empty($content['field_image'])) : ?>
        <div class="item-image">
          <?php print render($content['field_image']); ?>  
        </div>
      <?php endif; ?>
      <div class="block-poll-result">
        <h3><?php print $title_link; ?></h3>
        <ul>  
          <?php if (isset($content['poll_view_results'])) : ?>
            <?php print render($content['poll_view_results']); ?>
          <?php else : ?>
            <?php print render($content['poll_view_voting']); ?>
          <?php endif; ?>
        </ul>
        <div class="results-count"><?php print t('number of votes : @votes', array('@votes' => $votes)); ?></div>
      </div>
    </div>
  </div>
  <div class="block_events_item">
</div>
