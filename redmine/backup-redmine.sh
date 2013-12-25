#!/bin/sh

#Im using vagrant to build a redmine server, it is not usually what it is used for
#But it is so easy to build a virtualbox machine on it that im using it anyway :-)
#Usually it should be used to build dev environments, and for these cases doing a backup
#is useless since you dont store anything crucial on a dev environment 
#(provisioning should do the trick on this case).
#The machine is a precise32: http://files.vagrantup.com/precise32.box 

VAGRANT_HOME_DIR=$HOME/workspace/works/redmine/vagrant
VAGRANT_BOX=$VAGRANT_HOME_DIR/package.box
BACKUP_DIR="$HOME/Ubuntu One/redmine-backup"

echo "Boxing Vagrant machine"
cd $VAGRANT_HOME_DIR
vagrant package
echo "Moving $VAGRANT_BOX to $BACKUP_DIR"
mv "$VAGRANT_BOX" "$BACKUP_DIR"
echo "done"
