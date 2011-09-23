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

struct Game {
    int lives;
    int snakeParts;
    int speed;
    int points;
    int screenWidth;
    int screenHeight;

    time_t timeStart;
    time_t timeEnd;
};

static void set_properties(struct Game* const game, const int speed);


static void
set_properties(struct Game* const game, const int speed)
{
  game->speed = speed;
}

struct Game*
init_game()
{
  struct Game* game = malloc(sizeof(struct Game));
  if(game == NULL) {
    printf("Error while trying to allocate memory");
    exit(1);
  }
  
  reset_game(game);

  return game;
}

void
free_game(struct Game* const game)
{
  free(game);
}

void
reset_game(struct Game* const game)
{
  game->lives = 3;
  game->snakeParts = 3;
  game->points = 0;
  game->screenHeight = 200;
  game->screenWidth = 300;
  
  set_properties(game, 3);
}

void
start_game(struct Game* const game)
{
  time(&(game->timeStart));
}

void
end_game(struct Game* const game)
{
  time(&(game->timeEnd));
}

time_t
get_duration(const struct Game* const game)
{  
  return difftime(game->timeEnd, game->timeStart);
}

int
get_lives(const struct Game* const game)
{
  return game->lives;
}

void
add_points(struct Game* const game, const int points)
{
  game->points = points;
}

int
get_points(const struct Game* const game)
{
  return game->points;
}

int
add_life(struct Game* const game)
{
  if(game->lives < MAX_LIVES) {
    game->lives = game->lives + 1;
    return 1;
  } else {
    return 0;
  }
}

int
remove_life(struct Game* const game)
{
  if(game->lives > 0) {
    game->lives = game->lives - 1;
    return 1;
  } else {
    return 0;
  }
}

void
add_snakePart(struct Game* const game)
{
  game->snakeParts = game->snakeParts + 1;
}

