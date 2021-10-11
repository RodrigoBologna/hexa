/**
 * @file
 * Perform anything related with the components.
 *
 */
 (function ($, Drupal, drupalSettings) {
  'use strict';

  /*
   * Property preparation.
   */
  Drupal.behaviors.components_color = {
    attach: function (context) {
      if (context != document) {
        return;
      }

      $('.paragraph, .product').each(function() {
        var color = $(this).prop('style').color;

        if (typeof color == 'undefined') {
          return;
        }

        $(this).css('background-color', color);
      });
    }
  }

})(jQuery, Drupal, drupalSettings);
