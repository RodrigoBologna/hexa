<?php

namespace Drupal\training\Form;

use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\user\UserInterface;


class ClientForm extends FormBase {

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'training_form';
  }

  public function buildForm(array $form, FormStateInterface $form_state) {
    $form_state->disableCache();
    $form['#title'] = $this->t('Set user configuration preferences');

    $form['slogan'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Slogan'),
      '#description' => $this->t('Set a Slogan for your customers see'),
      '#default_value' => $this->t('Daft punk - Instant Crush'),
      '#required' => FALSE,
    ];

    $form['actions']['#type'] = 'actions';
    $form['actions']['submit'] = [
      '#type' => 'submit',
      '#value' => $this->t('Save'),
      '#button_type' => 'primary',
    ];

    return $form;
  }


  public function submitForm(array &$form, FormStateInterface $form_state) {
    $this->updateConfig($form_state);
  }

  public function updateConfig(FormStateInterface $form_state) {
    \Drupal::configFactory()->getEditable('system.site')->set('slogan', (string) $form_state->getValue('slogan'))->save();
  }

}
