<?php

namespace Drupal\hexa\Form;

use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Implements an example form.
 */
class ActiveLanguageForm extends FormBase {

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'hexa_active_language_form';
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $form_state->disableCache();
    $form['#title'] = $this->t('Select the active language');

    $form['language'] = [
      '#type' => 'radios',
      '#title' => t('Select the active language'),
      '#description' => t('This option will determine which language to activate during the installation.'),
      // @TODO: remove the hard-coded languages and retrieve them from Drupal.
      '#options' => [
        'en' => t('English'),
        'pt-br' => t('Portuguese (Brasil)'),
      ],
      '#default_value' => 'en',
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
  public function submitForm(array &$form, FormStateInterface $form_state) {
    $lang = (string) $form_state->getValue('language');

    \Drupal::configFactory()->getEditable('system.site')->set('default_langcode', $lang)->save();
  }

}
