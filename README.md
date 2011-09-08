# TheOpenSnake

TheOpenSnake is free snake game for linux, windows, and mac osx

## How to Install

### Before to start!

Please merge this branchs: gui-lnx with master.

	git clone https://github.com/Geeno1989/TheOpenSnake.git
	git branch gui-master
	git checkout gui-master
	FOR LNX: git merge gui-lnx
	FOR WIN: git merge gui-win

#### Ubuntu/Debian

First you have to install dependencies:

    # apt-get update
    # apt-get install build-essential libgtk3.0 libgtk3.0-dev

Then fix your GTK path:

    $ export CPATH=$CPATH:/usr/include/gtk-3.0
    $ export CPATH=$CPATH:/usr/include/glib-3.0/
    $ export CPATH=$CPATH:/usr/lib/glib-3.0/include/
    $ export CPATH=$CPATH:/usr/include/pango-1.0/
    $ export CPATH=$CPATH:/usr/lib/gtk-3.0/include/
    $ export CPATH=$CPATH:/usr/include/atk-1.0/


####  Archlinux
    # pacman -Syu
    # pacman -S gtk3
    
    
#### Windows

	Coming Soon...


### Compile 

#### Makefile

    $ ./autogen.sh
    $ ./configure
    $ make
    # make install
    
#### Console (Linux)
	$ gcc -Wall -DICONS_DIR=\""../share/icons"\" -o snake main.c main.h core/sys.h gui/gui.c gui/gui.h `pkg-config --cflags --libs gtk+-3.0`
	
#### Console (Windows)
	$ gcc -Wall -o snake main.c main.h core/sys.h gui/gui.c gui/gui.h
	
    
### Unistalling

    # make uninstall

	
## Support

Source: https://github.com/Geeno1989/ & https://github.com/PTKDev/

IRC: chat.freenode.net at #ptkdev
