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
#include "game.h"
#include "error.h"

#include <assert.h>
#include <stdlib.h>

static const unsigned int MAX_LIVES = 3;

static const unsigned int INITIAL_LENGTH = 3;
static const unsigned int INITIAL_LIVES  = 3;
static const int INITIAL_POINTS = 0;

enum Direction {
  UP,
  DOWN,
  LEFT,
  RIGHT
};

struct SnakePart {
  unsigned int gridPositionX;
  unsigned int gridPositionY;
  enum Direction direction;
  
  struct SnakePart* next; 
};

struct Snake {
  struct SnakePart* parts;
  unsigned int nParts;
  
  unsigned int lives;
  int points;
};

static struct SnakePart*
create_snake_parts(Game* game);

static struct SnakePart*
create_snake_parts(Game* game)
{
  assert(game != NULL);
  
  unsigned int gridPositionX = (unsigned int) get_grid_width(game) / 2;
  unsigned int gridPositionY = (unsigned int) get_grid_height(game) / 2;
  
  struct SnakePart* part = malloc(sizeof(*part));
  
  if (part == NULL) {
    no_memory_error();
  }
  
  part->next = NULL;
  part->gridPositionX = gridPositionX;
  part->gridPositionY = gridPositionY;
    
  set_cell(game, gridPositionX, gridPositionY, SNAKE);
  
  unsigned int i;
  for (i=1; i<INITIAL_LENGTH; ++i) {
  
    struct SnakePart* k = malloc(sizeof(*k));
    
    if (k == NULL) {
      no_memory_error();
    }
    
    k->next = NULL;
    k->gridPositionX = gridPositionX;
    k->gridPositionY = gridPositionY;
    
    struct SnakePart* p = part;
    while(p != NULL) {
      p = p->next;
    }
    
    p = k;
  }
  
  return part;
}

unsigned int
get_snake_lives(const Game* game)
{
  assert(game != NULL);
  
  const struct Snake* snake = get_snake(game);
  
  return snake->lives;
}

bool
add_snake_life(Game* game)
{
  assert(game != NULL);
  
  struct Snake* snake = get_snake(game);
  
  if (snake->lives < MAX_LIVES) {
    snake->lives++;
    return true;
  } else {
    return false;
  }
}

bool
remove_snake_life(Game* game)
{
  assert(game != NULL);
  
  struct Snake* snake = get_snake(game);
  
  snake->lives--;
  
  if (snake->lives > 0) {
    return true;
  } else {
    return false;
  }
}

struct Snake*
create_snake(Game* game)
{
  assert(game != NULL);
  
  struct Snake* snake = malloc(sizeof(*snake));
  
  if (snake == NULL) {
    no_memory_error();
  }
  
  snake->points = INITIAL_POINTS;
  snake->lives = INITIAL_LIVES;
  snake->parts = create_snake_parts(game);
  
  return snake;
}

void
destroy_snake(Game* game)
{
  assert(game != NULL);
  
  struct Snake* snake = get_snake(game);
  
  struct SnakePart* part = snake->parts;
  
  struct SnakePart* p;
  
  while (part != NULL) {
    p = part;
    part = part->next;
    
    free(p);
  }
}

void
add_snake_part(Game* game)
{
  assert(game != NULL);
  
  struct Snake* snake = get_snake(game);
  
  snake->nParts++;
  
  struct SnakePart* part = snake->parts;
  
  struct SnakePart* k = malloc(sizeof(*k));
  
  if (k == NULL) {
    no_memory_error();
  }
  
  k->next = NULL;
  
  while (part->next != NULL) {
   part = part->next;
  }
 
  k->direction = part->direction;
  k->gridPositionX = part->gridPositionX;
  k->gridPositionY = part->gridPositionY;
  part->next = k;
}

void
move_snake(Game* game)
{
  assert(game != NULL);
  
  struct Snake* snake = get_snake(game);
  
  struct SnakePart* p = snake->parts;
  
  enum Direction direction;
  while (p != NULL) {
    direction = p->direction;
    
    set_cell(game, p->gridPositionX, p->gridPositionY, EMPTY);
    
    if        (p->direction == UP) {
      p->gridPositionY++;
      
    } else if (p->direction == DOWN) {
      p->gridPositionY--;
      
    } else if (p->direction == LEFT) {
      p->gridPositionX++;
      
    } else if (p->direction == RIGHT) {
      p->gridPositionX--;
    }
    
    set_cell(game, p->gridPositionX, p->gridPositionY, SNAKE);
    
    p = p->next;
    
    if(p != NULL) {
      p->direction = direction;
    }
    
  }
}

