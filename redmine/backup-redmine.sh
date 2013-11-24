#!/bin/sh

#Im using vagrant to build a redmine server, it is not usually what it is used for
#But it is so easy to build a virtualbox machine on it that im using it anyway :-)
#Usually it should be used to build dev environments, and for these cases doing a backup
#is useless since you dont store anything crucial on a dev environment 
#(provisioning should do the trick on this case).
#The machine is a precise32: http://files.vagrantup.com/precise32.box 

VAGRANT_VIRTUALBOX_MACHINE=$HOME/.vagrant.d/boxes/precise32/virtualbox
VAGRANT_HOME_DIR=$HOME/workspace/works/redmine/vagrant
BACKUP_DIR="$HOME/Ubuntu One/redmine-backup"

echo "Halting Vagrant machine"
cd $VAGRANT_HOME_DIR
vagrant halt
echo "Copying $VAGRANT_VIRTUALBOX_MACHINE to $BACKUP_DIR"
cp -pr "$VAGRANT_VIRTUALBOX_MACHINE" "$BACKUP_DIR"
echo "running Vagrant again"
vagrant up
echo "done"
