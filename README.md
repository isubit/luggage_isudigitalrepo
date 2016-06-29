# luggage_isudigitalrepo

ISU Digital Repository integration for Luggage

## Requirements

This module requires a patched version of feeds_oai_pmh. Apply these patches:

* https://www.drupal.org/files/d7_initial_install-1842598.patch (see https://www.drupal.org/node/1842598)
* https://www.drupal.org/files/issues/2383997-7.patch (see https://www.drupal.org/node/2383997)

## Installation

1. Apply the patches in the **Requirements** section
2. `drush en -y luggage_isudigitalrepo`
3. Go to import/publications, and enter:
   * **URL of OAI-PMH endpoint:** http://lib.dr.iastate.edu/do/oai/ 
   * **Set to fetch** Your collection in the Digital Repository
4. Go to admin/config/search/apachesolr and disable indexing of the 'Publication' content type
5. Go to admin/structure/views/nojs/config-item/digital_repository/default/footer/area and change 'set_name' in the link URL to your Digital Repository collection ID
6. Go to admin/structure/views/nojs/config-item/digital_repository/publications/footer/area and change 'set_name' in the link URL to your Digital Repository collection ID