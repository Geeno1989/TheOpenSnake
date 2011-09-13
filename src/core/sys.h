/*
 *	TheOpenSnake is free snake game for linux, windows, and mac osx
 *		Copyright (C) 2011  TheOpenSnake Team
 *
 *		This program is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		This program is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * 
 */
 
#ifndef SYS_H


#define SYS_H

#define MY_ENCODING "ISO-8859-1"
#ifdef _WIN32
#include <windows.h>
#endif
#define TITLE "TheOpenSnake"
typedef enum DIRECTION
{
    STOP = 0,
	UP = 1,
    DOWN = 2,
    RIGHT = 3,
	LEFT = 4,
	NOT_INIZIALIZED = 5
} DIRECTION;


typedef struct snakePart{
DIRECTION	direction_new;
DIRECTION	direction_old;
float startx;
float stopx;
float starty;
float stopy;
}snakePart_t;


#endif
