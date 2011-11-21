<?php
?>

<div>
  <?php if ($amount_title) : ?>
    <h3 class="title"><?php print $amount_title;?></h3>
  <?php endif; ?>
  <?php print render($amount_form) ?>

  <?php if ($method_title) : ?>
    <h3 class="title"><?php print $method_title;?></h3>
  <?php endif; ?>
</div>
