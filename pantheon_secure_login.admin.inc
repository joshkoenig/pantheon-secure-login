<?php

/**
 * @file
 * Admin page callbacks for the Pantheon Secure Login module.
 */

/**
 * Function to deliver the admin form.
 */
function pantheon_secure_login_admin_form($form, &$form_state) {
  if (!pantheon_secure_login_is_pantheon()) {
    $form['disabled'] = array(
      '#type' => 'markup',
      '#value' => '<p>'. t('You are not running this module on Pantheon, so it cannot be configured.') .'</p>',
    );
    return $form;
  }
  # TODO: warn if enabling this for the first time.
  # TODO: check cookie domain and security settings.
  $form['pantheon_secure_login_enabled'] = array(
    '#type' => 'radios',
    '#title' => t('Redirect logins and logged-in traffic to HTTPS.'),
    '#options' => array('disabled' => t('Disabled'), 'enabled' => t('Enabled')),
    '#default_value' => variable_get('pantheon_secure_login_enabled', 'disabled'),
    '#description' => t('Force logins and logged-in users onto HTTPS using the "gotpantheon" domain?'),
  );

  $domain_options = array(
    'pantheon.io' => t('pantheon.io'),
    'gotpantheon.com' => t('gotpantheon.com'),
  );

  $form['pantheon_secure_login_pantheon_domain'] = array(
    '#type' => 'radios',
    '#title' => t('What Pantheon domain does your website use?'),
    '#options' => $domain_options,
    '#default_value' => variable_get('pantheon_secure_login_pantheon_domain', 'pantheon.io'),
  );
  $form['pantheon_secure_login_live_domain'] = array(
    '#title' => t('Standardize my live traffic on a standard domain name.'),
    '#type' => 'textfield',
    '#description' => t('Fully qualified domain name to standardize on in LIVE for non-logged in users. For google and SEO goodness.'),
    '#default_value' => variable_get('pantheon_secure_login_live_domain'),
  );
  return system_settings_form($form);
}

/**
 * Validate the FQDN part so it's not a bunk domain.
 *
 * Borrowed regex from http://stackoverflow.com/questions/4654453/validating-if-string-is-a-fqdn-codeigniter
 *
 * TODO: awesomesauce checking if we are on Pantheon.
 */
function pantheon_secure_login_admin_form_validate($form, &$form_state) {
  if ($form_state['input']['pantheon_secure_login_live_domain'] != '') {
    if (preg_match('/(?=^.{1,254}$)(^(?:(?!\d|-)[a-z0-9\-]{1,63}(?<!-)\.)+(?:[a-z]{2,})$)/i', $form_state['input']['pantheon_secure_login_live_domain']) == 0) {
      form_set_error('pantheon_secure_login_live_domain', t('This is not a valid domain name'));
      return;
    }
    # TODO: curl the domain, determine if on Pantheon. For great justice.
  }
}