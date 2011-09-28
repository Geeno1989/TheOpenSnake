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

#include <assert.h>
#include <stdlib.h>

static const unsigned int GRID_MIN_WIDTH = 5;
static const unsigned int GRID_MIN_HEIGHT = 5;

struct Grid {
  enum Cell** cells;
  
  unsigned int width;
  unsigned int height;
};

static void
init_grid(struct Grid* grid);

static Cell**
create_matrix(const unsigned int width, const unsigned int height);

static void
init_grid(struct Grid* grid)
{
  assert(grid != NULL);
  
  const unsigned int width = grid->width;
  const unsigned int height = grid->height;
  
  int i;
  for(i=0; i<width; ++i) {
    int j;
    for(j=0; j<height; ++j) {
      if( (i == width-1) ||
          (j == height-1) ||
          (i == 0) ||
          (j == 0)) {
        grid->cells[i][j] = WALL;
      }
      else {
        grid->cells[i][j] = EMPTY;
      }
    }
  }
}

static enum Cell**
create_matrix(const unsigned int width, const unsigned int height)
{ 
  enum Cell** cell = calloc(width, sizeof(*cell));
  
  if (cell == NULL) {
    no_memory_error();
  } 
  
  int i;
  for (i=0; i<width; ++i) {
    cell[i] = calloc(height, sizeof(*cell[i]));
    
    if(cell[i] == NULL) {
      no_memory_error();
    }
  }
  
  return cell;
}

enum Cell
get_cell(const Game* game, const unsigned int x, const unsigned int y)
{
  assert(game != NULL);
  
  struct Grid* grid = get_grid(game);
  
  assert(x < grid->width && y < grid->height);
  
  return grid->cells[x][y];
}

void
set_cell(Game* game, 
         const unsigned int x,
         const unsigned int y,
         enum Cell cell)
{
  assert(game != NULL);
  
  struct Grid* grid = get_grid(game);
  
  assert(x < grid->width && y < grid->height);
  
  grid->cells[x][y] = cell;
}

struct Grid*
create_grid(Game* game, const unsigned int width, const unsigned int height)
{
  assert(game != NULL);
  assert(width >= GRID_MIN_WIDTH && height >= GRID_MIN_HEIGHT);
  
  Grid* grid = malloc(sizeof(*grid));
  
  if(grid == NULL) {
    no_memory_error();
  }
  
  grid->width = width;
  grid->height = height;
  
  enum Cell** cell = create_matrix(width, height);
  
  grid->cells = cell;
  
  init_grid(grid);
  
  return grid;
}

void
destroy_grid(Game* game)
{
  assert(game != NULL);
  
  struct Grid* grid = get_grid(game);
  
  const unsigned int width = grid->width;
  
  unsigned int i;
  for (i=0; i<width; ++i) {
    free(grid->cells[i]);  
  }
  
  free(grid->cells);
  
  free(grid);
}

unsigned int
get_grid_width(const Game* game)
{
  return get_grid(game)->width;
}

unsigned int
get_grid_height(const Game* game)
{
  return get_grid(game)->height;
}
