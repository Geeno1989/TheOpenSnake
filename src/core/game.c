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

#include <stdlib.h>
#include "game.h"

static void
set_properties(Game* game, int speed);

static void
set_properties(Game* game, int speed)
{
  game->speed = speed;
}

Game*
init_game()
{
  Game* game = malloc(sizeof(Game));
  
  reset_game(game);

  return game;
}

void
free_game(Game* game)
{
  free(game);
}

void
reset_game(Game* game)
{
  game->lives = 3;
  game->snakeParts = 3;
  game->points = 0;
  
  set_properties(game, 3);
}

void
start_game(Game* game)
{
  time(&(game->timeStart));
}

void
end_game(Game* game)
{
  time(&(game->timeEnd));
}

time_t
get_duration(Game* game)
{  
  return difftime(game->timeEnd, game->timeStart);
}

int
get_lives(Game* game)
{
  return game->lives;
}

void
add_points(Game* game, int points)
{
  game->points = points;
}

int
get_points(Game* game)
{
  return game->points;
}

bool
add_life(Game* game)
{
  if(game->lives < 3) {
    game->lives = game->lives + 1;
    return true;
  } else {
    return false;
  }
}

bool
remove_life(Game* game)
{
  if(game->lives > 0) {
    game->lives = game->lives - 1;
    return true;
  } else {
    return false;
  }
}

void
add_snakePart(Game* game)
{
  game->snakeParts = game->snakeParts + 1;
}
