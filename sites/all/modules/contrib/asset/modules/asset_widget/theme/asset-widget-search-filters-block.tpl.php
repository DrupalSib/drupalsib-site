<?php
/**
 * @file
 * Asset widget search results header template.
 */
?>
<?php if (!empty($search_labels) || !empty($search_params)): ?>
  <div class="tab-contents-top tab-contents-top-empty">
<?php else: ?>
  <div class="tab-contents-top tab-contents-top-empty tab-contents-noparam">
<?php endif; ?>
  <div class="top"></div>
  <div class="mid">
    <?php if (!empty($search_labels) || !empty($search_params)): ?>
    <div class="links-a">
      <div class="inner">
        <?php if (!empty($search_labels)): ?>
        <ul class="asset-search-params-list">
          <?php $count = count($search_labels); ?>
          <?php $i = 1; ?>
          <?php foreach ($search_labels as $label): ?>
          <?php $classes = array(); ?>
          <?php if ($i == 1) $classes[] = 'first'; ?>
          <?php if ($i == $count) $classes[] = 'last'; ?>
          <li<?php if (!empty($classes)) print ' class="' . implode(' ', $classes) . '"'; ?>>
            <a href="javascript: void(0)"><?php print check_plain($label); ?></a>
          </li>
          <?php $i++; ?>
          <?php endforeach; ?>
        </ul>
        <?php endif; ?>
        <?php if (!empty($search_params)): ?>
        <div class="tooltip tooltip-parameters">
          <div class="tooltip-inner">
            <span class="pointer"></span>
            <div class="tooltip-title">
              <?php print ('Search parameters'); ?>
            </div>
            <?php foreach ($search_params as $field => $value): ?>
            <div class="title inner-el">
              <?php print t(drupal_ucfirst($field)) . ' : '; ?>
            </div>
            <div class="descrip inner-el">
              <?php print check_plain($value); ?>
            </div>
            <?php endforeach; ?>
          </div>
        </div>
        <?php endif; ?>
      </div>
    </div>
    <?php endif; ?>
    <?php /* We show switcher only if enough results */ ?>
    <?php if ($results > 3): ?>
    <div class="view-switch">
      <ul>
        <li class="first x3">
          <a href="javascript: void(0)" class="active" title="x3">
            <span class="ico"></span>
          </a>
        </li>
        <li class="last x5">
          <a href="javascript: void(0)" title="x5">
            <span class="ico"></span>
          </a>
        </li>
      </ul>
    </div>
    <?php endif; ?>
    <div class="buttons buttons-2 button-single">
      <?php /* <div class="button button-save button-ico">
      <a href="javascript: void(0)">
        <span class="ico"></span>
        <span class="ico-load"></span>
        <span class="text-a"><?php print t('Save search'); ?></span>
        <span class="text-b"><?php print t('Saved'); ?></span>
      </a>
    </div> */ ?>
      <div class="button button-modifier button-ico">
        <a href="javascript: void(0)" class="asset-widget-modify-search">
          <span class="ico"></span>
          <?php print ((!empty($search_labels)) ? t('Modify') : t('Search')); ?>
        </a>
      </div>
    </div>
  </div>
  <div class="bottom"></div>
</div>
