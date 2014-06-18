Asset
-----

Introduction
------------

The Asset module proposes a new approach to the media management in Drupal.
It provides new fieldable entity called Media Asset and the set of Media Asset example bundles.
Integration with CKEditor module provides the precise content management opportunity as you manipulate by fully rendered asset representation.

INSTALLATION:
------------
Download and enable the module as usual.
Enable supplied sample asset modules or create some asset types.

CKEDITOR configuration
----------------------
Configure an input format you wont to use with CKEditor and assets.
Enable "Convert asset tags to markup" filter and set it as a first at the "Filter processing order"

Follow the installation instructions of the CKEditor module.
Enable the ckeditor profile for the previously configured input format.

Make the following changes on the ckeditor profile edition page:

in the "Editor appearance" fieldset enable "Media assets" checkbox in the Plugins list, choose the desired buttons
of your asset types to be used in editor.

in the "Cleanup and output" fieldset we suggest to choose <br> "Enter mode" for now.

in the "Advanced options" fieldset set "HTML Entities" to "No" (At this moment it is a required option if you use the Asset module.)


Sample asset modules
--------------------
Audio
-----
Provides a simple audio assset with jplayer frontend.
Please follow the instructions of jplayer module to configure it properly.
To make the player look as it should inside the editor, please add the jplayer css to the ckeditor profile:
in the "CSS" tab of the ckeditor profile edition page choose "Define CSS" and add the proper path to the jplayer css into
"CSS file path" field. In most cases it should be: %hsites/all/modules/contrib/jplayer/theme/jplayer.css
