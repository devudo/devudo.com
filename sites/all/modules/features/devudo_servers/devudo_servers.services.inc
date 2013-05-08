<?php
/**
 * @file
 * devudo_servers.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function devudo_servers_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'api';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api';
  $endpoint->authentication = array(
    'services' => 'services',
    'services_oauth' => array(
      'oauth_context' => '',
      'credentials' => 'none',
      'authorization' => '',
    ),
  );
  $endpoint->server_settings = array(
    'formatters' => array(
      'json' => TRUE,
      'jsonp' => TRUE,
      'bencode' => FALSE,
      'php' => FALSE,
      'rss' => FALSE,
      'xml' => FALSE,
    ),
    'parsers' => array(
      'application/json' => TRUE,
      'application/vnd.php.serialized' => FALSE,
      'application/x-www-form-urlencoded' => FALSE,
      'application/xml' => FALSE,
      'multipart/form-data' => FALSE,
      'text/xml' => FALSE,
    ),
  );
  $endpoint->resources = array(
    'oauthlogin' => array(
      'actions' => array(
        'info' => array(
          'enabled' => '1',
          'settings' => array(
            'services_oauth' => array(
              'credentials' => 'none',
              'authorization' => '',
            ),
          ),
        ),
      ),
    ),
    'node' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
          'settings' => array(
            'services_oauth' => array(
              'credentials' => '',
              'authorization' => '',
            ),
          ),
        ),
        'update' => array(
          'enabled' => '1',
          'settings' => array(
            'services_oauth' => array(
              'credentials' => '',
              'authorization' => '',
            ),
          ),
        ),
      ),
    ),
    'system' => array(
      'actions' => array(
        'connect' => array(
          'enabled' => '1',
          'settings' => array(
            'services_oauth' => array(
              'credentials' => '',
              'authorization' => '',
            ),
          ),
        ),
      ),
    ),
    'user' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
          'settings' => array(
            'services_oauth' => array(
              'credentials' => 'none',
              'authorization' => '',
            ),
          ),
        ),
      ),
      'actions' => array(
        'login' => array(
          'enabled' => '1',
          'settings' => array(
            'services_oauth' => array(
              'credentials' => 'none',
              'authorization' => '',
            ),
          ),
        ),
        'logout' => array(
          'enabled' => '1',
          'settings' => array(
            'services' => array(
              'resource_api_version' => '1.0',
            ),
            'services_oauth' => array(
              'credentials' => '',
              'authorization' => '',
            ),
          ),
        ),
        'register' => array(
          'enabled' => '1',
          'settings' => array(
            'services_oauth' => array(
              'credentials' => '',
              'authorization' => '',
            ),
          ),
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['api'] = $endpoint;

  return $export;
}
