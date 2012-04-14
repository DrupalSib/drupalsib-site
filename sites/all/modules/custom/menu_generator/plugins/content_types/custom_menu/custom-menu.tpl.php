<div class="darker-bg">
  <div class="content-box-right-in" style="margin: 0;">
    <?php if (!empty($params['title'])): ?>
      <h4><?php print $params['title']; ?></h4>
    <?php endif; ?>
    <ul class="categories">
      <?php foreach ($categories as $name => $data): ?>
        <li>
          <a href="<?php print $data['url']; ?>"><?php print $name; ?></a> 
          <span>(<?php print $data['count']; ?>)</span>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
</div>
