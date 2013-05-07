<?php
/**
 * @file
 * devudo_connect..inc
 */

/**
 * Implements hook_default_oauthconnector_provider().
 */
function devudo_connect_default_oauthconnector_provider() {
  $export = array();

  $provider = new stdClass();
  $provider->disabled = FALSE; /* Edit this to true to make a default provider disabled initially */
  $provider->name = 'github';
  $provider->title = 'GitHub';
  $provider->url = 'https://api.github.com';
  $provider->consumer_advanced = array(
    'oauth2' => 1,
    'signature method' => 'HMAC-SHA1',
    'authentication realm' => '',
    'request token endpoint' => '/oauth/request_token',
    'authorization scope' => 'public_repo',
    'authorization endpoint' => 'https://github.com/login/oauth/authorize',
    'access token endpoint' => 'https://github.com/login/oauth/access_token',
  );
  $provider->mapping = array(
    'fields' => array(
      'uid' => array(
        'resource' => 'https://api.github.com/user',
        'method post' => 0,
        'field' => 'id',
        'querypath' => FALSE,
        'sync_with_field' => '',
      ),
      'mail' => array(
        'resource' => 'https://api.github.com/user',
        'method post' => 0,
        'field' => 'email',
        'querypath' => FALSE,
        'sync_with_field' => 'mail',
      ),
      'name' => array(
        'resource' => 'https://api.github.com/user',
        'method post' => 0,
        'field' => 'login',
        'querypath' => FALSE,
        'sync_with_field' => 'name',
      ),
      'avatar' => array(
        'resource' => 'https://api.github.com/user',
        'method post' => 0,
        'field' => 'avatar_url',
        'querypath' => FALSE,
        'sync_with_field' => 'picture',
      ),
    ),
    'format' => 'json',
  );
  $export['github'] = $provider;

  $provider = new stdClass();
  $provider->disabled = FALSE; /* Edit this to true to make a default provider disabled initially */
  $provider->name = 'twitter';
  $provider->title = 'Twitter';
  $provider->url = 'https://api.twitter.com';
  $provider->consumer_advanced = array(
    'oauth2' => 0,
    'signature method' => 'HMAC-SHA1',
    'authentication realm' => '',
    'request token endpoint' => '/oauth/request_token',
    'authorization scope' => '',
    'authorization endpoint' => '/oauth/authorize',
    'access token endpoint' => '/oauth/access_token',
  );
  $provider->mapping = array(
    'fields' => array(
      'uid' => array(
        'resource' => 'https://api.twitter.com/1/account/verify_credentials.json',
        'method post' => 0,
        'field' => 'id',
        'querypath' => FALSE,
        'sync_with_field' => '',
      ),
      'name' => array(
        'resource' => 'https://api.twitter.com/1/account/verify_credentials.json',
        'method post' => 0,
        'field' => 'name',
        'querypath' => FALSE,
        'sync_with_field' => 'name',
      ),
      'avatar' => array(
        'resource' => 'https://api.twitter.com/1/account/verify_credentials.json',
        'method post' => 0,
        'field' => 'profile_image_url',
        'querypath' => FALSE,
        'sync_with_field' => 'picture',
      ),
    ),
    'format' => 'json',
  );
  $export['twitter'] = $provider;

  return $export;
}
