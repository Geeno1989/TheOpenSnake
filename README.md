# TheOpenSnake

TheOpenSnake is free snake game for linux, windows, and mac osx

## How to Install

### Before to start!

Please merge this branchs: gui-lnx with master.

	git clone git@github.com:PTKDev/TheOpenSnake.git
	git branch gui-master
	git checkout gui-master
	git merge gui-lnx

#### Ubuntu/Debian

First you have to install dependencies:

    # apt-get update
    # apt-get install build-essential libgtk2.0 libgtk2.0-dev

Then fix your GTK path:

    $ export CPATH=$CPATH:/usr/include/gtk-2.0
    $ export CPATH=$CPATH:/usr/include/glib-2.0/
    $ export CPATH=$CPATH:/usr/lib/glib-2.0/include/
    $ export CPATH=$CPATH:/usr/include/pango-1.0/
    $ export CPATH=$CPATH:/usr/lib/gtk-2.0/include/
    $ export CPATH=$CPATH:/usr/include/atk-1.0/


####  Archlinux
    # pacman -Syu
    # pacman -S gtk2


### Compile 

#### Makefile

    $ ./autogen.sh
    $ ./configure
    $ make
    # make install
    
#### Console
	$ gcc -Wall -DICONS_DIR=\""../share/icons"\" -o snake main.c main.h core/sys.h gui/gui.c gui/gui.h `pkg-config --cflags --libs gtk+-2.0`
	
    
### Unistalling

    # make uninstall

	
## Support

Source: https://github.com/PTKDev/

IRC: chat.freenode.net at #ptkdev
