<?php

/**
 * @file
 * Provides the aspam administration settings.
 */

/**
 * Form callback; administrative settings for aspam.
 */
function aspam_admin_settings()
{
    $form = array();
    $form['aspam_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Aspam widget width'),
    '#default_value' => variable_get('aspam_width', 50),
    '#maxlength' => 3,
    '#description' => t('Width of aspam widget'),
    '#required' => true,
  );

    $form['aspam_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Aspam widget height'),
    '#default_value' => variable_get('aspam_height', 50),
    '#maxlength' => 3,
    '#description' => t('Height of aspam widget'),
    '#required' => true,
  );

    $form['aspam_length'] = array(
    '#type' => 'textfield',
    '#title' => t('Aspam char length'),
    '#default_value' => variable_get('aspam_length', 6),
    '#maxlength' => 3,
    '#description' => t('Length of aspam widget'),
    '#required' => true,
  );

    $form['aspam_ttime'] = array(
    '#type' => 'textfield',
    '#title' => t('Char transform time'),
    '#default_value' => variable_get('aspam_ttime', 1000),
    '#maxlength' => 5,
    '#description' => t('Transformation time in milliseconds'),
    '#required' => true,
  );

    $form['aspam_wtime'] = array(
    '#type' => 'textfield',
    '#title' => t('Char waiting time'),
    '#default_value' => variable_get('aspam_wtime', 1500),
    '#maxlength' => 5,
    '#description' => t('Pause time after every char in milliseconds'),
    '#required' => true,
  );

    $form['aspam_symbols'] = array(
    '#type' => 'textfield',
    '#title' => t('Symbols'),
    '#default_value' => variable_get('aspam_symbols', 'lowercase|uppercase|digits'),
    '#description' => t('Symbols lowercase|uppercase|digits'),
    '#required' => true,
  );

    $form['aspam_security'] = array(
    '#type' => 'fieldset',
    '#title' => t('Aspam Security'),
    '#collapsible' => true,
    '#collapsed' => true,
  );

    $form['aspam_security']['aspam_rsa_encryption'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable RSA encryption'),
    '#default_value' => variable_get('aspam_rsa_encryption', false),
    '#maxlength' => 7,
    '#description' => t('Enable JavaScript RSA encryption'),
    '#required' => false,
  );

    $form['aspam_security']['aspam_pem_private_key'] = array(
    '#type' => 'textarea',
    '#title' => t('Private key'),
    '#default_value' => variable_get('aspam_pem_private_key', false),
    '#description' => t('PEM formatted private key'),
    '#required' => false,
  );

    $form['aspam_security']['aspam_pem_public_key'] = array(
    '#type' => 'textarea',
    '#title' => t('Public key'),
    '#default_value' => variable_get('aspam_pem_public_key', false),
    '#description' => t('PEM formatted public key'),
    '#required' => false,
  );

    $form['aspam_security']['aspam_security_markup'] = array(
    '#type' => 'markup',
    '#markup' => '
      <b>Generate a private key</b>
      <pre>openssl genrsa -out rsa_1024_priv.pem 1024</pre>
      <br />
      <b>Generate a public key</b>
      <pre>openssl rsa -pubout -in rsa_1024_priv.pem -out rsa_1024_pub.pem</pre>
    ',
  );

    $form['aspam_theme_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Aspam Theme Settings'),
    '#collapsible' => true,
    '#collapsed' => true,
  );

    $form['aspam_theme_settings']['aspam_backgroudcolor'] = array(
    '#type' => 'textfield',
    '#title' => t('Background color'),
    '#default_value' => variable_get('aspam_backgroudcolor', '#5BAE09'),
    '#maxlength' => 7,
    '#description' => t('Aspam background color'),
    '#required' => true,
  );

    $form['aspam_theme_settings']['aspam_theme_settings']['aspam_bordercolor'] = array(
    '#type' => 'textfield',
    '#title' => t('Border color'),
    '#default_value' => variable_get('aspam_bordercolor', '#4F9607'),
    '#maxlength' => 7,
    '#description' => t('Aspam border color'),
    '#required' => true,
  );

    $form['aspam_theme_settings']['aspam_borderwidth'] = array(
    '#type' => 'textfield',
    '#title' => t('Border width'),
    '#default_value' => variable_get('aspam_borderwidth', 1),
    '#maxlength' => 2,
    '#description' => t('Aspam border width'),
    '#required' => true,
  );

    $form['aspam_theme_settings']['aspam_chcolor'] = array(
    '#type' => 'textfield',
    '#title' => t('Char color'),
    '#default_value' => variable_get('aspam_chcolor', '#5BAE09'),
    '#maxlength' => 7,
    '#description' => t('Color of chars'),
    '#required' => true,
  );

    $form['aspam_theme_settings']['aspam_flopacity'] = array(
    '#type' => 'textfield',
    '#title' => t('Fill opacity'),
    '#default_value' => variable_get('aspam_flopacity', '0.8'),
    '#maxlength' => 7,
    '#description' => t('Fill opacity'),
    '#required' => true,
  );

    $form['aspam_theme_settings']['aspam_chstroke'] = array(
    '#type' => 'textfield',
    '#title' => t('Char stroke color'),
    '#default_value' => variable_get('aspam_chstroke', '#448107'),
    '#maxlength' => 7,
    '#description' => t('Char stroke color'),
    '#required' => true,
  );

    $form['aspam_theme_settings']['aspam_chswidth'] = array(
    '#type' => 'textfield',
    '#title' => t('Char stroke width'),
    '#default_value' => variable_get('aspam_chswidth', 2),
    '#maxlength' => 5,
    '#description' => t('Char stroke width'),
    '#required' => true,
  );

    $form['aspam_theme_settings']['aspam_chwsize'] = array(
    '#type' => 'textfield',
    '#title' => t('Char width size'),
    '#default_value' => variable_get('aspam_chwsize', '1.0'),
    '#maxlength' => 5,
    '#description' => t('Scale of char width'),
    '#required' => true,
  );

    $form['aspam_theme_settings']['aspam_chhsize'] = array(
    '#type' => 'textfield',
    '#title' => t('Char height size'),
    '#default_value' => variable_get('aspam_chhsize', '1.0'),
    '#maxlength' => 5,
    '#description' => t('Scale of char height'),
    '#required' => true,
  );

    $form['aspam_theme_settings']['aspam_padlockopacity'] = array(
    '#type' => 'textfield',
    '#title' => t('Padlock opacity'),
    '#default_value' => variable_get('aspam_padlockopacity', '0.3'),
    '#maxlength' => 5,
    '#description' => t('Padlock opacity value'),
    '#required' => true,
  );

    $form['aspam_theme_settings']['aspam_padlockfillcolor'] = array(
    '#type' => 'textfield',
    '#title' => t('Padlock fill color'),
    '#default_value' => variable_get('aspam_padlockfillcolor', '#000000'),
    '#maxlength' => 7,
    '#description' => t('Padlock fill color hex value'),
    '#required' => true,
  );

    $form['aspam_theme_settings']['aspam_paddingleft'] = array(
    '#type' => 'textfield',
    '#title' => t('Padding left'),
    '#default_value' => variable_get('aspam_paddingleft', 'auto'),
    '#maxlength' => 7,
    '#description' => t('Padding left int value or auto'),
    '#required' => true,
  );

    $form['aspam_theme_settings']['aspam_paddingtop'] = array(
    '#type' => 'textfield',
    '#title' => t('Padding top'),
    '#default_value' => variable_get('aspam_paddingtop', 'auto'),
    '#maxlength' => 7,
    '#description' => t('Padding top int value or auto'),
    '#required' => true,
  );

    return system_settings_form($form);
}

/**
 * Validation function for aspam_admin_settings().
 *
 * @see aspam_admin_settings()
 */
function aspam_admin_settings_validate($form, &$form_state)
{
    $awidth = $form_state['values']['aspam_width'];
    if (!empty($awidth) && !is_numeric($awidth)) {
        form_set_error('aspam_width', t('The aspam width must be an integer.'));
    }

    $aheight = $form_state['values']['aspam_height'];
    if (!empty($aheight) && !is_numeric($aheight)) {
        form_set_error('aspam_height', t('The aspam height must be an integer.'));
    }

    $alength = $form_state['values']['aspam_length'];
    if (!empty($alength) && !is_numeric($alength)) {
        form_set_error('aspam_length', t('The aspam char length must be an integer.'));
    }
}
