# TheOpenSnake

TheOpenSnake is free snake game for linux, windows, and mac osx

## How to Install

### Before to start!

Please merge this branchs: gui-lnx with master.

	git clone https://github.com/Geeno1989/TheOpenSnake.git
	git branch gui-master
	git checkout gui-master
	git merge gui-win

#### Windows

	Coming Soon...


### Compile 
    
#### Console
	$ gcc -Wall -o snake main.c main.h core/sys.h gui/gui.c gui/gui.h `pkg-config --cflags --libs gtk+-2.0`

	
## Support

Source: https://github.com/Geeno1989/
