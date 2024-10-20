#ifndef _INPUT_H_
#define _INPUT_H_

#include <ncurses.h>
#include "snake.h"


// __ FUNCTIONS ________________________________________________________________
// * Get the user input and return a direction according to the input. 
// * return: the new direction of the snake or -1 if 
// *         the direction don't change. 
int get_dir_from_input(); 

#endif