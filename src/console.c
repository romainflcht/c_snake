#include "console.h"


int init_console()
{
    /*
     * Initialise the stdscr console window, no cursor and no echo. 
     */
    
    if (NULL == initscr())
        return 1; 

    timeout(GAME_SPEED);  
    curs_set(0); 
    noecho();

    return 0;
}


void draw_board()
{
    /*
     * Draw the game board to the screen. 
     */
    box(stdscr, 0, 0); 
    mvwaddstr(stdscr, 0, 2, " SNAKE GAME "); 
    return;
}

void draw_score(SNAKE_t *snake)
{
    /*
     * Draw the snake len on the game board. 
     */
    wprintw(stdscr, "| score : %ld ", snake->len); 
    return; 
}