INTRODUCTION
------------

Aspam is a challenge-response test for web forms to determine whether the 
user is human. Aspam offer the new idea of challenge-response test to 
block form submissions by spambots and automated scripts.

 * For a full description of the module, visit the project page:
   https://drupal.org/project/aspam or https://github.com/msztorc/aspam

 * To submit bug reports and feature suggestions, or to track changes:
   https://drupal.org/project/issues/aspam


REQUIREMENTS
------------

This module requires the following modules:

 * Captcha (https://drupal.org/project/captcha)
 * jQueryUpdate (https://drupal.org/project/jquery_update)



INSTALLATION
------------
 
 * Install as you would normally install a contributed Drupal module. See:
   https://drupal.org/documentation/install/modules-themes/modules-7
   for further information.

 * You may want to disable Toolbar module, since its output clashes with
   Administration Menu.


CONFIGURATION
-------------
 
 * Configure user permissions in Administration » People » Permissions:

   - Use the administration pages and help (System module)

     The top-level administration categories require this permission to be
     accessible. The administration menu will be empty unless this permission
     is granted.

   - Access administration menu

     Users in roles with the "Access administration menu" permission will see
     the administration menu at the top of each page.

   - Display Drupal links

     Users in roles with the "Display drupal links" permission will receive
     links to drupal.org issue queues for all enabled contributed modules. The
     issue queue links appear under the administration menu icon.

 * Customize the menu settings in Administration » Configuration and modules »
   Administration » Administration menu.

 * To prevent administrative menu items from appearing twice, you may hide the
   "Management" menu block.


MAINTAINERS
-----------

Current maintainers:
 * Miroslaw Sztorc - https://www.drupal.org/u/msztorc