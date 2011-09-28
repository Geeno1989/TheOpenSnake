/*
* TheOpenSnake is free snake game for linux, windows, and mac osx
* Copyright (C) 2011 TheOpenSnake Team
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
*
*/

#include "game.h"
#include "error.h"

#include <stdlib.h>
#include <assert.h>

struct Game {
  enum Difficulty difficulty;
  Grid* grid;
  Snake* snake;
  
  unsigned int screenWidth;
  unsigned int screenHeight;
};

struct Game*
create_game(enum Difficulty difficulty,
            unsigned int gridHeight,
            unsigned int gridWidth,
            unsigned int screenHeight,
            unsigned int screenWidth)
{
    Game* game = malloc(sizeof(*game));
    
    if(game == NULL)
      no_memory_error();
    
    game->difficulty = difficulty;
    game->grid = create_grid(game, gridWidth, gridHeight);
    game->snake = create_snake(game);
    game->screenWidth = screenWidth;
    game->screenHeight = screenHeight;
    
    return game;
}

void
destroy_game(struct Game* game)
{
  assert(game != NULL);
  
  destroy_grid(game);
  destroy_snake(game);
  
  free(game);
}

Grid*
get_grid(const struct Game* game)
{
  assert(game != NULL);  
  
  return game->grid;
}

Snake*
get_snake(const struct Game* game)
{
  assert(game != NULL);
  
  return game->snake;
}

Difficulty
get_difficulty(const struct Game* game)
{
  assert(game != NULL);
  
  return game->difficulty;
}

unsigned int 
get_screen_width(const struct Game* game)
{
  assert(game != NULL);
  
  return game->screenWidth;
}

unsigned int 
get_screen_height(const struct Game* game)
{
  assert(game != NULL);
  
  return game->screenHeight;
}

