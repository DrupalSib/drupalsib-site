<?php
/**
 * @file
 * Template for full build mode section node.
 */
?>
<div id="ds_main" class="clear-block">
  <div id="ds_main_content">
    <div id="ds_section_top">
      <div class="ds_title">
        <h1><?php print $title; ?></h1>
        <div class="block-motscles">
          <div class="block-for-motscles"></div>
        </div>
      </div>
      <?php if (!empty($description)): ?>
        <div class="ds_sub_title">
          <div class="ds_social_dossier">
            <?php print $description; ?>
          </div>
        </div>
      <?php endif; ?>
      <div class="enddiv"></div>
      <div class="ds_block_search_content">
        <?php if (!empty($tabs)): ?>
          <div class="ds_block_filter_search">
            <div class="ds_link">
              <ul>
                <li>
                  <?php print $tabs; ?>
                </li>
              </ul>
            </div>
          </div>
        <?php endif; ?>
        <?php if ($dossier_list): ?>
          <ul>
            <?php print $dossier_list; ?>
          </ul>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
