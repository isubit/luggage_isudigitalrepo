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
   * **Set to fetch** The value of a setSpec element from [this list](http://lib.dr.iastate.edu/do/oai/?verb=ListSets) 
4. Go to admin/config/search/apachesolr and disable indexing of the 'Publication' content type
5. Go to admin/structure/views/nojs/config-item/digital_repository/default/footer/area and change 'set_name' in the link URL to the setSpec value from step 3, without the 'publication:' prefix
6. Go to admin/structure/views/nojs/config-item/digital_repository/publications/footer/area and change 'set_name' in the link URL to the setSpec value from step 3, without the 'publication:' prefix

## Digital Repository Publication Map

This module provides a block for displaying a map similar to the one on the [ISU Digital Repository homepage](http://lib.dr.iastate.edu/). Before you can use the block, the map widget must be enabled by the Digital Repository staff for your publication set. Please [email the Digital Repository staff](mailto:digirep@iastate.edu) to have this done, then follow these steps: 

1. Visit the Digital Repository collection page ( e.g. [Entomology](http://lib.dr.iastate.edu/ent/) ) with the map you want to embed. Click the 'Embed' link on the lower, left-hand corner.
2. On the next page, click the 'Standard' button to generate the map widget for your collection.
3. On the same page, code should have appeared in the large text box under Step 3. From the lines starting with **mapContext**, **site_title**, and **site_link**, copy down the text appearing between the double quote marks.
4. On your site, go to admin/structure/block/manage/luggage_isudigitalrepo/bepress_widget/configure and enter the text you copied down in the previous step into the corresponding text fields.
5. Configure the placement and other settings to your liking, then save the block.
