<?php
/**
 * @file
 * luggage_isudigitalrepo.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function luggage_isudigitalrepo_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'publications';
  $feeds_importer->config = array(
    'name' => 'Publications',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsOAIHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'last_fetched_timestamp' => '',
        'earliest_timestamp' => '',
        'use_dates' => FALSE,
        'to' => array(),
        'from' => array(),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsISUDigitalRepositoryParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'creator',
            'target' => 'field_publication_authors',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'contributor',
            'target' => 'field_publication_authors',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'date',
            'target' => 'field_publication_date:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'url_viewcontent',
            'target' => 'field_publication_pdf:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'url_noviewcontent',
            'target' => 'field_publication_link:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'setspec_raw',
            'target' => 'field_publication_sets',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'publication',
        'language' => 'und',
        'author' => 0,
        'authorize' => 1,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '3600',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['publications'] = $feeds_importer;

  return $export;
}
