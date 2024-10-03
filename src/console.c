#include "console.h"


int init_console()
{
    /*
     * Initialise the stdscr console window, no cursor and no echo. 
     */
    
    if (NULL == initscr())
        return 1; 

    timeout(100);  
    curs_set(0); 
    noecho();

    return 0;
}


void draw_board()
{
    box(stdscr, 0, 0); 
    mvwaddstr(stdscr, 0, 2, " SNAKE GAME "); 
    return;
}