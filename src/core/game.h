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


typedef struct Game {
    int lives;
    int snakeParts;
    int speed;
    int points;
    
    time_t timeStart;
    time_t timeEnd;
} Game;


/*
  Parameter:    None
  Returns:      A Game struct instance
  Description:  This function initializes the instance and sets all default parameters
*/
Game*
init_game();



/*
  Parameter:    A Game struct instance 
  Returns:      Nothing
  Description:  This function deallocates the Game struct instance
*/
void
free_game(Game* game);



/*
  Parameter:    A Game struct instance
  Returns:      Nothing
  Description:  Resets the instance to default values;
*/
void
reset_game(Game* game);



/*
  Parameter:    A Game struct instance
  Returns:      Nothing
  Description:  Starts the Game and stores the current time in game->timeStart
*/
void
start_game(Game* game);



/*
  Parameter:    A Game struct instance
  Returns:      Nothing
  Description:  Ends the Game and stores the current time in game->timeEnd
*/
void
end_game(Game* game);



/*
  Parameter:    A Game struct instance
  Returns:      The duration of the game expressed in time_t
  Description:  Calculates the duration of the game
                from game->timeStart to game->timeStop
*/
time_t
get_duration(Game* game);



/*
  Parameter:    A Game struct instance
  Returns:      Number of lives left
  Description:  Return the number of lives left from game->lives
*/
int
get_lives(Game* game);


/*
  Parameter:    A Game struct instance, Points expressed in Int
  Returns:      Nothing
  Description:  Adds points to game->points
*/
void
add_points(Game* game, int points);



/*
  Parameter:    A Game struct instance
  Returns:      Points expressed in int
  Description:  Returns the points from game->points
*/
int
get_points(Game* game);



/*
  Parameter:    A Game struct instance
  Returns:      0 if maximum of lives ha been reached
                1 if succesfully added the life
  
  Description:  Adds 1 life to game->lives
*/
int
add_life(Game* game);



/*
  Parameter:    A Game struct instance
  Returns:      0 if there are no more lives to remove (the snake is dead)
                1 if succesfully removed the life
  
  Description:  Removes 1 life from game->lives
*/
int
remove_life(Game* game);



/*
  Parameter:    A Game struct instance
  Returns:      Nothing
  Description:  Adds 1 snake part to game->snakeParts
*/
void
add_snakePart(Game* game);

