<?php
/**
 * @file
 * Commerce-related functions for the hexa install tasks.
 */

use Drupal\commerce_store\Entity\Store;
use Drupal\commerce_store\Entity\StoreType;

/**
 * Prepare the commerce structure.
 */
function hexa_commerce_preparation($profile_type) {
  _hexa_commerce_create_defaults();

  $function_name = sprintf('_hexa_commerce_prepare_%s_profile_type', $profile_type);
  $function_name();
}

/**
 * Create the defaults - store type, store and currency.
 */
function _hexa_commerce_create_defaults() {
  $address = [
    'country_code' => 'US',
    'address_line1' => '123 Street Drive',
    'locality' => 'Beverly Hills',
    'administrative_area' => 'CA',
    'postal_code' => '90210',
  ];

  $currency = 'USD';

  $currency_importer = \Drupal::service('commerce_price.currency_importer');
  $currency_importer->import($currency);

  $store = Store::create([
    'type' => 'default',
    'uid' => 1,
    'name' => 'Default',
    'mail' => 'admin@example.com',
    'address' => $address,
    'default_currency' => $currency,
    'billing_countries' => ['US'],
  ]);

  $store->save();

  // If needed, this sets the store as the default store.
  $store_storage = \Drupal::service('entity_type.manager')->getStorage('commerce_store');
  $store_storage->markAsDefault($store);
}

/**
 * Prepare the brochure profile type.
 */
function _hexa_commerce_prepare_brochure_profile_type() {

}

/**
 * Prepare the commerce profile type.
 */
function _hexa_commerce_prepare_commerce_profile_type() {

}
