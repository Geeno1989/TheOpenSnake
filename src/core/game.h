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

#include <time.h>
#include "sys.h"
#ifdef LINUX
#include <stdbool.h>
#endif

typedef struct Game {
    int lives;
    int snakeParts;
    int speed;
    int points;
    
    time_t timeStart;
    time_t timeEnd;
} Game;

Game*
init_game();

void
free_game(Game* game);

void
reset_game(Game* game);

void
start_game(Game* game);

void
end_game(Game* game);

time_t
get_duration(Game* game);

int
get_lives(Game* game);

void
add_points(Game* game, int points);

int
get_points(Game* game);

#ifdef LINUX
bool
add_life(Game* game);
#endif

BOOL
add_life(Game* game);

#ifdef LINUX
bool
remove_life(Game* game);
#endif

BOOL 
remove_life(Game* game);

void
add_snakePart(Game* game);
