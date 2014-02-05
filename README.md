Pantheon Secure Login
=====================

If you are a free or personal customer, and you want to use SSL without having to pay the extra cost associated with a Pro plan and a dedicated IP address, this module may help. It will allow you to secure your Drupal admin login behind Pantheon's free SSL cert for the "gotpantheon" domain name, while using your public-facing domain for all other requests.

This is only useful if you are running your site on the Pantheon platform:

https://www.getpantheon.com

The ideal user is someone running a Personal site (e.g. a blog or small project site) who is concerned with the security of their logins and user sessions, but is fine with their public-facing content being sent in the clear. If you don't mind doing your own logins on "live-yoursite.gotpantheon.com" then you can keep yourself secure for free.

**NOTE: Proof of Concept**

This is a free example showing how you can use some features of Pantheon environment configuration within your site to good effect. However, it is provided without warranty or support. Use at your own risk, etc, etc, etc.

Use Free SSL for Logins
=======================

This module enforces SSL for authenticated users on the Pantheon platform using the free "gotpantheon" domain and certificate. If you are on a personal plan and would like to secure your content author or admin login, you can use this module to do so without having to pay for an upgrade plan or an SSL certificate.

Please note that you will need to be careful if you are redirecting incoming requests using this documentation:

http://helpdesk.getpantheon.com/customer/portal/articles/368354-redirect-incoming-requests

For users who are looking to standardize on a domain for SEO purposes, there is a simple UI to support both use-cases in this module. You should remove logic from settings.php if you use this module.


Installation
============

Install as a normal module, and then visit admin/configuration/pantheon-secure-login to configure. It should be self-explanatory from there.

TODO
====

This is currently a proof of concept/work in progress. There are a number of things to improve:

- Construct definitive "gotpantheon" domains for redirects.
- Do some more extensive validation on the "live domain name" value.
