<div id="rdr-embed" data-width="100%" data-height="445" style="width=100%; max-width:666px; border=0;"></div>
<script>
  window.rdrAsync = function() {
    RDR.init({
      mapContext: <?php print $map_context; ?>,
      datastreamHost: "datastream.bepress.com",
      datastreamPort: "443",
      datastreamStaticRoot: "//assets.bepress.com/current/",
      colorCode: "custom",
      customColor: "CCCC99",
      customSaturation: "0",
      customLightness: "0",
      institution_title: "Iowa State University",
      site_title: <?php print $site_title; ?>,
      site_link: <?php print $site_link; ?>,
      instCountryCode: "us",
      instCity: "Ames",
      instRegion: "Iowa",
      instCountry: "United States",
      origin: window.location.origin,
      refreshRate: 3600000,
      homepageMap: 0,
      publicationMap: 1,
      embedMap: 1,
      zoom: 1,
      minZoom: 1,
      stats_host: "https://www.bepress.com",
    });
  };
</script>
<script src="https://assets.bepress.com/current/shared/embed/rdr.js" async="true"></script>