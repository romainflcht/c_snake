#ifndef _CONSOLE_H_
#define _CONSOLE_H_


#include <ncurses.h>
#include "snake.h"

// __ DEFINITIONS ______________________________________________________________
#define GAME_SPEED 200

// __ FUNCTIONS ________________________________________________________________
int init_console(); 
void draw_board(); 
void draw_score(SNAKE_t *snake); 
#endif