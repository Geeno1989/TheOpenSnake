# TheOpenSnake

TheOpenSnake is free snake game for linux, windows, and mac osx

## How to Install

### Before to start!

Download SourceCode With Git:

	git clone https://github.com/Geeno1989/TheOpenSnake.git

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
    
    
#### Windows

	Coming Soon...


### Compile 

#### Makefile
    $ ./autogen.sh
    $ make
    # make install
    
#### Console (Linux)
	$ gcc -Wall -DICONS_DIR=\""../share/icons"\" -o snake main.c main.h core/sys.h core/game.c core/game.h gui/gui_lnx.c gui/gui_lnx.h gui/images.c gui/images.h libs/OpenGl.h `pkg-config --cflags --libs gtk+-2.0`
	
#### Console (Windows)
	$ gcc -Wall -o snake main.c main.h core/sys.h core/game.c core/game.h core/GrapichSnake.c gui/gui_win.c gui/gui_win.h gui/images.c gui/images.h libs/GrapichSnake.h libs/OpenGl.h
	
    
### Unistalling

    # make uninstall

	
## Support

Source: https://github.com/Geeno1989/ & https://github.com/PTKDev/

IRC: chat.freenode.net at #ptkdev
