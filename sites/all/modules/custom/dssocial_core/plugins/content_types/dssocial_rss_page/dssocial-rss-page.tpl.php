<?php
/**
 * @file
 * Rss page.
 */
?>
<div class="icontent">
  <div class="icontent-inner">
    <div class="icontent-area">             
      <div class="content-inner-wrapper">
        <div class="content-left">
          <div class="content">
          <p><?php print t('На данный момент на сайте присутствуют следующие RSS потоки:'); ?></p>
          <?php if (!empty($variables['sections'])): ?>
            <table border="0" cellpadding="2" cellspacing="2" width="464">
              <tbody>
                <?php foreach ($variables['sections'] as $section): ?>
                <tr>
                  <td style="width: 10px;">
                    <?php print $section['img']; ?>
                  </td>
                  <td>
                    <?php print $section['title']; ?>
                  </td>
                </tr>
                <?php endforeach; ?>
              </tbody>
            </table>
          <?php else: ?>
            <p><?php print t('RSS потоки не найдены:'); ?></p>
          <?php endif; ?>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
