<?php

/**
 * @file
 * Lists available colors and color schemes.
 */

/**
 * These colors are imported from Bootstrap (similar variables).
 *
 * @see _color.scss
 */

$logo_url = 'logo.svg';

$info = [
  // Available colors and color labels used in theme.
  'fields' => [
    'base' => t('Background (page)'),
    'header' => t('Header (region) - background'),
    'footer' => t('Footer (region) - background'),
    'link' => t('Navigation (links)'),
    'link_footer' => t('Navigation (links) - footer'),
    'active' => t('Active (items)'),
    'cta' => t('CTA (button)'),
    'cta_bg' => t('CTA (button) - background'),
    'dots' => t('Dots'),
    'dots_active' => t('Dots active'),
    'shadow' => t('Shadow (borders)'),
    'text' => t('Text'),
    'text_hover' => t('Text (hover)'),
  ],
  'schemes' => [
    'default' => [
      'title' => t('Default'),
      'colors' => [
        'base' => '#ffffff',
        'header' => '#e5e5e5',
        'footer' => '#c2c2c2',
        'link' => '#c700b7',
        'link_footer' => '#c70000',
        'active' => '#f51167',
        'cta' => '#333333',
        'cta_bg' => '#8c8c8c',
        'dots' => '#c7254e',
        'dots_active' => '#f9f2f4',
        'shadow' => '#eeeeee',
        'text' => '#333333',
        'text_hover' => '#000000',
      ],
    ],
  ],

  // CSS files (excluding @import) to rewrite with new color scheme.
  'css' => [
    'css/color.css',
  ],

  // Files to copy.
  'copy' => [
    $logo_url,
  ],

  '#attached' => [
    'drupalSettings' => [
      'color' => [
        // Put the logo path into JavaScript for the live preview.
        'logo' => theme_get_setting('logo.url', 'hx'),
      ],
    ],
  ],
];
