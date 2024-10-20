#ifndef _CONSOLE_H_
#define _CONSOLE_H_


#include <ncurses.h>
#include "snake.h"

// __ DEFINITIONS ______________________________________________________________
#define GAME_SPEED 200

// __ FUNCTIONS ________________________________________________________________
// * Initialise the stdscr console window, no cursor and no echo. 
int init_console(); 

// * Draw the game board to the screen. 
void draw_board(); 

// * Draw the snake len on the game board. 
void draw_score(SNAKE_t *snake); 

#endif