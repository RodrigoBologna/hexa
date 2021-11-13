/**
 * @file
 * Perform functionality from barba.js related to page transition.
 *
 */
 (function ($, Drupal, drupalSettings) {
  'use strict';

  Drupal.barba = {
    'init': function() {
      // Validate if the barba object is initialized. Race conditions probably
      // controlled through the dependencies on theme's libraries declaration.
      if (typeof barba != 'object') {
        return;
      }

      barba.init({

      });
    }
  }

  /*
   * Features to run during the page load.
   */
  Drupal.behaviors.transitions = {
    attach: function (context) {
      // @TODO: we need to prepare the container and set the proper options
      // before initializing Barba.
      // @see https://barba.js.org/docs/getstarted/intro/
      //Drupal.barba.init();

      $('#fullview').fullView({
        navbar: '.header',
        element: 'section, .section',
        dots: true,
        dotsPosition: 'right',
        easing: 'ease-out',
        backToTop: true,
        offset: 0, // Not needed as the header is fixed.
        speed: 300,
      });
    }
  }

})(jQuery, Drupal, drupalSettings);
