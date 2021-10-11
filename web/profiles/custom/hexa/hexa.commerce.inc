<?php
/**
 * @file
 * Commerce-related functions for the hexa install tasks.
 */

use Drupal\commerce_price\Price;
use Drupal\commerce_product\Entity\Product;
use Drupal\commerce_product\Entity\ProductAttributeValue;
use Drupal\commerce_product\Entity\ProductVariation;
use Drupal\commerce_product\Entity\ProductVariationType;
use Drupal\commerce_store\Entity\Store;
use Drupal\Core\File\FileSystemInterface;

define('HEXA_COMMERCE_DEFAULT', 'hexa');

/**
 * Prepare the commerce structure.
 */
function hexa_commerce_preparation($profile_type) {
  // Shared features between the profile types.
  _hexa_commerce_create_defaults();
  _hexa_commerce_create_products();

  $function_name = sprintf('_hexa_commerce_prepare_%s_profile_type', $profile_type);
  $function_name();
}

/**
 * Create the defaults - store type, store and currency.
 */
function _hexa_commerce_create_defaults() {
  $info = [
    'USD' => 'US',
    'BRL' => 'BR',
  ];

  foreach ($info as $currency => $country) {
    $address = [
      'country_code' => $country,
      'address_line1' => '123 Street Drive',
      'locality' => 'Beverly Hills',
      'administrative_area' => 'CA',
      'postal_code' => '90210',
    ];

    $currency_importer = \Drupal::service('commerce_price.currency_importer');
    $currency_importer->import($currency);

    $store = Store::create([
      'type' => 'default',
      'uid' => 1,
      'name' => 'Default',
      'mail' => 'oliveirafrafa@gmail.com',
      'address' => $address,
      'default_currency' => $currency,
      'billing_countries' => $country,
    ]);

    $store->save();
  }

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

/**
 * Create the product variation and attributes.
 */
function _hexa_commerce_create_products() {
  // Use the default variation type instead of creating a new one.
  // $variation_type = ProductVariationType::create([
    // 'status' => 1,
    // 'id' => 'variation_type',
    // 'label' => 'Variation Type With Color',
    // 'orderItemType' => 'default',
    // 'generateTitle' => TRUE,
  // ]);
  // $variation_type>save();

  $variation_type = ProductVariationType::load('default');
  $attributes = _hexa_commerce_create_product_attributes($variation_type);

  $price = new Price('24.99', 'BRL');
  $price2 = new Price('39.99', 'BRL');

  $variation = ProductVariation::create([
    'type' => 'default',
    'sku' => 'test-product-01',
    'status' => 1,
    'price' => $price,
    'attribute_color' => $attributes['color']['red'],
    'attribute_size' => $attributes['size']['p'],
  ]);
  $variation->save();

  $variation2 = ProductVariation::create([
    'type' => 'default',
    'sku' => 'test-product-02',
    'status' => 1,
    'price' => $price2,
    'attribute_color' => $attributes['color']['yellow'],
    'attribute_size' => $attributes['size']['g'],
  ]);
  $variation2->save();

  _hexa_commerce_create_product_types([$variation, $variation2]);
}

/**
 * Create the product attributes.
 */
function _hexa_commerce_create_product_attributes(ProductVariationType $variation_type) {
  // This creation is not needed as we are using a config for it.
  // $color_attribute = ProductAttribute::create([
  //   'id' => 'color',
  //   'label' => t('Color'),
  // ]);
  // $color_attribute->save();

  // $size_attribute = ProductAttribute::create([
  //   'id' => 'size',
  //   'label' => t('Size'),
  // ]);
  // $size_attribute->save();

  // $field_manager = \Drupal::service('commerce_product.attribute_field_manager');
  // $field_manager->createField($color_attribute, $variation_type->id());
  // $field_manager->createField($size_attribute, $variation_type->id());

  $blue = ProductAttributeValue::create([
    'attribute' => 'color',
    'name' => 'blue',
  ]);
  $blue->save();

  $red = ProductAttributeValue::create([
    'attribute' => 'color',
    'name' => 'red',
  ]);
  $red->save();

  $yellow = ProductAttributeValue::create([
    'attribute' => 'color',
    'name' => 'yellow',
  ]);
  $yellow->save();

  $green = ProductAttributeValue::create([
    'attribute' => 'color',
    'name' => 'green',
  ]);
  $green->save();

  $p = ProductAttributeValue::create([
    'attribute' => 'size',
    'name' => 'p',
  ]);
  $p->save();

  $m = ProductAttributeValue::create([
    'attribute' => 'size',
    'name' => 'm',
  ]);
  $m->save();

  $g = ProductAttributeValue::create([
    'attribute' => 'size',
    'name' => 'g',
  ]);
  $g->save();

  return [
    'color' => [
      'blue' => $blue,
      'red' => $red,
      'yellow' => $yellow,
      'green' => $green,
    ],
    'size' => [
      'p' => $p,
      'm' => $m,
      'g' => $g,
    ],
  ];
}

/**
 * Create the product types.
 */
function _hexa_commerce_create_product_types(array $variations) {
  // $product_type = ProductType::create([
  //   'id' => 'dress',
  //   'label' => 'Dress - color and size',
  //   'status' => 1,
  //   'description' => 'This is the description of the product',
  //   'variationType' => 'default',
  //   'injectVariationFields' => TRUE,
  // ]);
  // $product_type->save();

  // commerce_product_add_variations_field($product_type);
  // commerce_product_add_stores_field($product_type);
  // commerce_product_add_body_field($product_type);

  $store = Store::load(1);
  $images = _hexa_commerce_prepare_images([['tesla-black.png', 'tesla-model-3.jpg', 'tesla-model-s.jpg'], ['tesla-model-x-red.jpg']]);

  $i = $variation_key = 0;

  foreach ($images as $image) {
    if (empty($image)) {
      continue;
    }

    $product = Product::create([
      'uid' => $i,
      'type' => 'default',
      'title' => 'Product ' . $i,
      'stores' => [$store],
      'variations' => [$variations[$variation_key]],
      'body' => _hexa_commerce_get_dummy_text(),
      'field_product_image' => $image,
    ]);

    $product->save();

    $i++;
    // Switch between the two variations for each loop.
    $variation_key = $variation_key == 0 ? 1 : 0;
  }
}

/**
 * Save the images to file system and returns the File object.
 */
function _hexa_commerce_prepare_images($image_list) {
  foreach ($image_list as $filenames) {
    $images[] = _hexa_commerce_get_files($filenames);
  }

  return $images;
}

/**
 * Save the files and get its data.
 */
function _hexa_commerce_get_files($filenames) {
  $profile_path = \Drupal::service('file_system')->realpath(drupal_get_path('profile', HEXA_COMMERCE_DEFAULT));
  $files = array();

  foreach ($filenames as $filename) {
    $image_path = $profile_path . '/images/products/' . $filename;
    $content = file_get_contents($image_path);
    $file = file_save_data($content, 'public://' . $filename, FileSystemInterface::EXISTS_REPLACE);

    $file_info = explode('.', $filename, 1);

    $files[] = [
      'target_id' => $file->id(),
      'alt' => strtolower($file_info[0]),
      'title' => ucfirst($file_info[0]),
    ];
  }

  return $files;
}

/**
 * Get dummy text for description field.
 */
function _hexa_commerce_get_dummy_text() {
  return 'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.';
}
