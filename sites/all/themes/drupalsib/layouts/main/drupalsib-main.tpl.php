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

<div id="ds_page">
    <div id="ds_page_inner">
        <div id="ds_header">
            <?php print $content['header']; ?>
        </div>
        <div id="ds_main">
            <div id="ds_main_inner">
                <div id="ds_main_left">
                    <?php print $content['content'];?>										
                </div>
                <div id="ds_main_sidebar">
                  <?php if (!empty($content['sidebar_top'])): ?>
                    <div class="ds_sidebar_content">
                      <?php print $content['sidebar_top']; ?>
                    </div>
                  <?php endif; ?>
                  <?php if (!empty($content['sidebar'])): ?>
                    <div class="ds_sidebar_content">
                      <?php print $content['sidebar']; ?>
                    </div>
                  <?php endif; ?>
                  <?php if (!empty($content['sidebar_bottom'])): ?>
                    <div class="ds_sidebar_content">
                      <?php print $content['sidebar_bottom']; ?>
                    </div>
                  <?php endif; ?>
                </div>
            </div>
        </div>
        <div id="ds_footer">
          <div id="ds_footer_top">
            <?php if (!empty($content['footer_top'])): ?>
              <?php print $content['footer_top']; ?>
            <?php endif; ?>
          </div>
          <?php print $content['footer_bottom']; ?>
        </div>
    </div>
</div>


