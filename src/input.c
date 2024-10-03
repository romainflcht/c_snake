#include "input.h"



// * Get the user input and return a direction according to the input. 
// * return: the new direction of the snake or -1 if 
// *         the direction don't change. 
int get_dir_from_input()
{
    int key_code; 

    key_code = wgetch(stdscr); 

    switch (key_code)
    {
        case 'z':
            return UP; 

        case 's':
            return DOWN; 

        case 'q':
            return LEFT; 

        case 'd':
            return RIGHT; 
    
        default:
            return -1; 
    }
}


