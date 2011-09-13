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

#include <stdio.h>
#include <stdlib.h>
#include "game.h"

static const int MAX_LIVES = 3;

static void
set_properties(Game* const game, const int speed);

static void
set_properties(Game* const game, const int speed)
{
  game->speed = speed;
}

Game*
init_game()
{
  Game* const game = malloc(sizeof(Game));
  if(game == NULL) {
    printf("Error while trying to allocate memory");
    exit(1);
  }
  
  reset_game(game);

  return game;
}

void
free_game(Game* const game)
{
  free(game);
}

void
reset_game(Game* const game)
{
  game->lives = 3;
  game->snakeParts = 3;
  game->points = 0;
  
  set_properties(game, 3);
}

void
start_game(Game* const game)
{
  time(&(game->timeStart));
}

void
end_game(Game* const game)
{
  time(&(game->timeEnd));
}

time_t
get_duration(const Game* const game)
{  
  return difftime(game->timeEnd, game->timeStart);
}

int
get_lives(const Game* const game)
{
  return game->lives;
}

void
add_points(Game* const game, const int points)
{
  game->points = points;
}

int
get_points(const Game* const game)
{
  return game->points;
}

int
add_life(Game* const game)
{
  if(game->lives < MAX_LIVES) {
    game->lives = game->lives + 1;
    return 1;
  } else {
    return 0;
  }
}

int
remove_life(Game* const game)
{
  if(game->lives > 0) {
    game->lives = game->lives - 1;
    return 1;
  } else {
    return 0;
  }
}

void
add_snakePart(Game* const game)
{
  game->snakeParts = game->snakeParts + 1;
}

