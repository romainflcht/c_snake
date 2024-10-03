#include "console.h"


// * Initialise the stdscr console window, no cursor and no echo. 
int init_console()
{
    if (!initscr())
        return 1; 

    timeout(GAME_SPEED);  
    curs_set(0); 
    noecho();

    return 0;
}


// * Draw the game board to the screen. 
void draw_board()
{
    box(stdscr, 0, 0); 
    mvwaddstr(stdscr, 0, 2, " SNAKE GAME "); 
    return;
}


// * Draw the snake len on the game board. 
void draw_score(SNAKE_t *snake)
{
    wprintw(stdscr, "| score : %ld ", snake->len); 
    return; 
}