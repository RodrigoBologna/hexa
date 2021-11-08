<?php

namespace Drupal\hexa\Form;

use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\user\UserInterface;
use PhpParser\Node\Expr\Cast\String_;

/**
 * Implements an example form.
 */
class ClientSettingsForm extends FormBase {

  /**
   * Maximum length of username text field.
   *
   * Keep this under 191 characters so we can use a unique constraint in MySQL.
   */
  const ADDRESS_MAX_LENGTH = 120;

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'hexa_client_settings_form';
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $form_state->disableCache();
    $form['#title'] = $this->t('Configure client preferences');

    $form['name'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Name'),
      '#description' => $this->t('Name of your company to display for users.'),
      '#default_value' => t('Hexentials'),
      '#required' => TRUE,
    ];

    $form['slogan'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Slogan'),
      '#description' => $this->t('Slogan to display for the users.'),
      '#default_value' => t('The best products for your needs.'),
      '#required' => FALSE,
      '#maxlength' => self::ADDRESS_MAX_LENGTH,
    ];

    $form['mail'] = [
      '#type' => 'email',
      '#title' => $this->t('Email address'),
      '#default_value' => 'oliveirafrafa@gmail.com',
      '#description' => $this->t('E-mail address to display for the users.'),
      '#required' => TRUE,
    ];

    $form['phone_number'] = [
      '#type' => 'tel',
      '#title' => $this->t('Phone number'),
      '#description' => $this->t('Phone number to display for the users.'),
      '#default_value' => '+55 (19) 1111-1111',
      // @TODO; keep this commented out while we don't have a functionality to
      // auto-fill the special characters.
      // '#pattern' => '\(\d{2,}\) \d{4,}\-\d{4}',
    ];

    $form['whatsapp'] = [
      '#type' => 'tel',
      '#title' => $this->t('Phone number - WhatsApp'),
      '#description' => $this->t('WhatsApp phone number to display for the users.'),
      '#default_value' => '+55 (19) 22222-2222',
    ];

    $form['address'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Address'),
      '#description' => $this->t('Address to display for the users.'),
      '#default_value' => 'John Doe - 123 Main St. - City/State',
      '#required' => FALSE,
      '#maxlength' => UserInterface::USERNAME_MAX_LENGTH,
    ];

    $form['facebook'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Facebook'),
      '#description' => $this->t('Facebook to display for the users.'),
      '#default_value' => 'https://www.facebook.com/',
      '#required' => FALSE,
      '#maxlength' => UserInterface::USERNAME_MAX_LENGTH,
    ];

    $form['twitter'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Twitter'),
      '#description' => $this->t('Twitter to display for the users.'),
      '#default_value' => 'https://www.twitter.com/',
      '#required' => FALSE,
      '#maxlength' => UserInterface::USERNAME_MAX_LENGTH,
    ];

    $form['linkedin'] = [
      '#type' => 'textfield',
      '#title' => $this->t('LinkedIn'),
      '#description' => $this->t('LinkedIn to display for the users.'),
      '#default_value' => 'https://www.linkedin.com/',
      '#required' => FALSE,
      '#maxlength' => UserInterface::USERNAME_MAX_LENGTH,
    ];

    $form['instagram'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Instagram'),
      '#description' => $this->t('Instagram to display for the users.'),
      '#default_value' => 'https://www.instagram.com/',
      '#required' => FALSE,
      '#maxlength' => UserInterface::USERNAME_MAX_LENGTH,
    ];

    $form['copyright'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Copyright'),
      '#description' => $this->t('Copyright to display for the users.'),
      '#default_value' => t('© Copyright 2021 - Company name here'),
      '#required' => FALSE,
      '#maxlength' => UserInterface::USERNAME_MAX_LENGTH,
    ];

    $form['actions']['#type'] = 'actions';
    $form['actions']['submit'] = [
      '#type' => 'submit',
      '#value' => $this->t('Save'),
      '#button_type' => 'primary',
    ];

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function validateForm(array &$form, FormStateInterface $form_state) {
    $message = $this->t('The phone number is too short. Please enter a full phone number.');

    if (strlen($form_state->getValue('phone_number')) < 8) {
      $form_state->setErrorByName('phone_number', $message);
    }

    if (strlen($form_state->getValue('whatsapp')) < 8) {
      $form_state->setErrorByName('whatsapp', $message);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    $name = (string) $form_state->getValue('name');
    $mail = (String) $form_state->getValue('mail');
    $language = \Drupal::languageManager()->getCurrentLanguage()->getId();

    $user = \Drupal\user\Entity\User::create();
    $user->setPassword((strtolower($name)));
    $user->enforceIsNew();
    $user->setEmail($mail);
    $user->setUsername((strtolower($name)));
    $user->set("langcode", $language);
    $user->addRole('content_manager');
    $user->activate();
    $user->save();

    $this->updateConfiguration($form_state);
  }

  /**
   * Update the configuration values per installation data.
   */
  public function updateConfiguration(FormStateInterface $form_state) {
    \Drupal::configFactory()->getEditable('system.site')->set('slogan', (string) $form_state->getValue('slogan'))->save();

    \Drupal::configFactory()
      ->getEditable('hexa.settings')
      ->set('name', (string) $form_state->getValue('name'))
      ->set('address', (string) $form_state->getValue('address'))
      ->set('phone', (string) $form_state->getValue('phone_number'))
      ->set('whatsapp', (string) $form_state->getValue('whatsapp'))
      ->set('mail', (string) $form_state->getValue('mail'))
      ->set('facebook', (string) $form_state->getValue('facebook'))
      ->set('twitter', (string) $form_state->getValue('twitter'))
      ->set('linkedin', (string) $form_state->getValue('linkedin'))
      ->set('instagram', (string) $form_state->getValue('instagram'))
      ->set('copyright', (string) $form_state->getValue('copyright'))
      ->save();
  }
}
