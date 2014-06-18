<?php
/**
 * @file
 * @see template_preprocess_node()
 */ //kpr($image); die('asdf');
?>
<div class="cell" data-cell="<?php print $number; ?>"> 
  <?php print $image; ?>
  <div class="cell-overlay">
    <div class="overlay-content">
      <div class="tags">
      </div>
      <h3 class="title"><?php print $title; ?></h3>
    </div>
  </div>
  <a href="<?php print $link; ?>" class="slide-link card-style-overlay"></a>
</div>  