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

      $('.paragraph').each(function() {
        var style = $(this).prop('style');

        if (typeof style == 'undefined') {
          return;
        }

        $(this).css('background-color', $(this).css('color'));
      });
    }
  }

})(jQuery, Drupal, drupalSettings);
