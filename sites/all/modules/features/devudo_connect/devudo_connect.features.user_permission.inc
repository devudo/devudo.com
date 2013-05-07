<?php
/**
 * @file
 * devudo_connect.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function devudo_connect_user_default_permissions() {
  $permissions = array();

  // Exported permission: access connections tab.
  $permissions['access connections tab'] = array(
    'name' => 'access connections tab',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'connector',
  );

  // Exported permission: connect with oauthconnector_github.
  $permissions['connect with oauthconnector_github'] = array(
    'name' => 'connect with oauthconnector_github',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'connector',
  );

  // Exported permission: connect with oauthconnector_twitter.
  $permissions['connect with oauthconnector_twitter'] = array(
    'name' => 'connect with oauthconnector_twitter',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'connector',
  );

  return $permissions;
}
