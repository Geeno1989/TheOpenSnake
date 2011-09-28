#ifndef GAME_H
#define GAME_H

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

#include "bool.h"

typedef struct Game Game;
typedef struct Snake Snake;
typedef struct Grid Grid;

typedef enum Difficulty {
  EASY,
  MEDIUM,
  HARD
} Difficulty;

typedef enum Cell { 
  EMPTY,
  SNAKE,
  FOOD,
  WALL
} Cell;


/*********  game.c ***********/
Game*
create_game(Difficulty difficulty,
            unsigned int gridHeight,
            unsigned int gridWidth,
            unsigned int screenHeight,
            unsigned int screenWidth);

void
destroy_game(Game* game);
          
Grid*
get_grid(const Game* game);

Snake*
get_snake(const Game* game);

Difficulty
get_difficulty(const Game* game);

unsigned int 
get_screen_height(const Game* game);

unsigned int 
get_screen_width(const Game* game);
/******************************/



/*********  snake.c ***********/
void
destroy_snake(Game* game);

Snake*
create_snake(Game* game);

unsigned int
get_snake_lives(const Game* game);

bool
add_snake_life(Game* game);

bool
remove_snake_life(Game* game);

void
add_snake_part(Game* game);

void
move_snake(Game* game);

void
add_snake_points(Game* game, const unsigned int points);

void
remove_snake_points(Game* game, const unsigned int points);
/******************************/



/*********  grid.c ***********/
Grid*
create_grid(Game* game, const unsigned int width, const unsigned int height);

void
destroy_grid(Game* game);

void
set_cell(Game* game, const unsigned int x, const unsigned int y, Cell cell);

Cell
get_cell(const Game* game, const unsigned int x, const unsigned int y);

unsigned int
get_grid_width(const Game* game);

unsigned int
get_grid_height(const Game* game);
/******************************/

#endif

