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

      barba.init({});
    }
  }

  /*
   * Features to run during the page load.
   */
  Drupal.behaviors.barba = {
    attach: function (context) {
      Drupal.barba.init();
    }
  }

})(jQuery, Drupal, drupalSettings);
