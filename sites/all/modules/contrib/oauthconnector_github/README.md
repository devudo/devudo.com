OAuth Connector - GitHub
========================

A Drupal module that adds a preset for a GitHub provider when using the
OAuth Connector module.

Usage
-----

Use the preset by adding an OAuth provider:

    Structure > OAuth Connector > Add provider from preset > GitHub

In order to create a GitHub provider on your Drupal site, you'll need to
first [register a GitHub application][github-app-registration]. Use the
values below as a template for the values you'll need to provide:

Name: My GitHub Application
URL: http://www.mydrupalsite.com
Callback URL: http://www.mydrupalsite.com/connect/oauthconnector_github

After your app is created, you'll need to make note of the "Client
ID" and "Client Secret" that GitHub has generated for you. 

Dependencies
------------

- Drupal 7 core
- Modules
  - [Connector][connector]
  - [OAuth connector][oauthconnector]
  - [Http client][http_client]
  - [OAuth][oauth]
  - [Chaos tool suite][ctools]

<!-- Links -->
   [github-app-registration]: https://github.com/settings/applications/new
   [connector]:               http://drupal.org/project/connector
   [oauthconnector]:          http://drupal.org/project/oauthconnector
   [http_client]:             http://drupal.org/project/http_client
   [oauth]:                   http://drupal.org/project/oauth
   [ctools]:                  http://drupal.org/project/ctools
