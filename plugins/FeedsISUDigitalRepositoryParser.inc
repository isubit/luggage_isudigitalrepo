<?php

/**
 * @file
 * Implementation of FeedsParser::parse().
 *
 */

/**
 * Class definition for OAI-PMH Dublin Core metadata parser.
 */
class FeedsISUDigitalRepositoryParser extends FeedsOAIParser {

  /**
   * Implementation of FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {

    $result = parent::parse($source, $fetcher_result);

    foreach ($result->items as $index => $item) {
      foreach ($item['identifier'] as $value) {
        if (valid_url($value, TRUE) && strpos($value, 'viewcontent') !== FALSE) {
          $result->items[$index]['url_viewcontent'] = str_replace('&amp;', '&', $value);
          break;
        }
      }
      foreach ($item['identifier'] as $value) {
        if (valid_url($value, TRUE) && strpos($value, 'viewcontent') === FALSE) {
          $result->items[$index]['url_noviewcontent'] = str_replace('&amp;', '&', $value);
          break;
        }
      }
    }

    return $result;
  }

  /**
   * Return mapping sources.
   */
  public function getMappingSources() {
    self::loadMappers();
    $sources = parent::getMappingSources();
    drupal_alter('feeds_parser_sources', $sources, feeds_importer($this->id)->config['content_type']);
    $sources += array(
      'url_viewcontent' => array(
        'name' => t('URL to viewcontent'),
        'description' => t('First valid URL detected in dc:identifier elements that contains viewcontent in the URL.'),
      ),
      'url_noviewcontent' => array(
        'name' => t('URL to non-viewcontent'),
        'description' => t('First valid URL detected in dc:identifier elements that does not contain viewcontent in the URL.'),
      ),
    );
    
    return $sources;
  }
}
