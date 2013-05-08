<?php
/**
 * @file template.php
 *
 * 
 */

/**
 * Implements hook_block_view_alter()
 */
function deviant_preprocess_page(&$vars) {
  global $user;
  if ($user->uid) {
    $vars['primary_nav'] = array(
      '#theme' => 'item_list',
      '#attributes' => array('class' => array('menu nav pull-right')),
      '#items' => array(
        l(t('Dashboard'), "dashboard"),
        l($user->name, "user/$user->uid"),
        l(t('Logout'), "logout", array('attributes' => array('class' => array('muted')))),
      ),
    );
  }
}