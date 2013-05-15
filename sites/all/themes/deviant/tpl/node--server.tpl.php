<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>


  <header>
    <?php if ($title): ?>
      <a href="http://<?php print $node_url; ?>" target="_blank"><?php print $title; ?></a></h2>
    <?php endif; ?>
    
    <div class="pull-right">
      <?php print $user_picture; ?>
    </div>
  </header>

  <?php
    print render($content);
  ?>
</article> <!-- /.node -->
