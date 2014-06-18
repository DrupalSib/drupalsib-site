DCQ - Drupal Code Quality. Check code quality through git.

Installation and Usage

Requires phpcs and drupalcodesniffer. for installation of those see:
http://drupal.org/project/drupalcs

Installing local:
Simply turn the module and watch the informational messages.
The module will install all the necessary scripts. If your www-data user is not
enough rights to write into project directory, you will need to give him the
right to change the files in the project directory or install scripts checks by
manually.
The pre-commit_dcq script will analyse relevant committed files against the
Drupal coding standard and feedback errors and warnings.
In the event that you wish to commit your files regardless of the standards
errors do git commit --no-verify and git will not execute the pre-commit hooks

Copy files from dcq_remote_scripts directory into your remote repository
.git/hooks/ directory. Also you can use symlinks for post-receive and
post-receive_dcq files.

post-receive hook will run every time you commit to remote repository.
He does not interrupt the process of adding files. It only checks them if it
finds errors, it sends an error report by e-mail specified in the settings of
the script. This is useful in cases where a senior developer controls the
quality of the code other developers on the project.

Script post-receive_dcq used on the remote repository, requires a mandatory
settings.

Ignoring the check code with using a configuration file:

You can ignore the check for files and folders (third-party modules or
features). See example in admin/config/development/dcq

File .dcq_ignore should be under version control, in order to make it work
for all developers. And to be able to use by hook post-receive for checking
on a remote server.

To the git could run a scripts and hooks, you should set permissions for files
"Allow run file as program"
