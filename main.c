#include <ncurses.h>

#include "snake.h"
#include "console.h"
#include "input.h"



int main() {
    int     ret; 
    int     max_x; 
    int     max_y; 
    int     direction; 
    SNAKE_t *snake; 

    ret = init_console();

    if (ret) 
        return 1; 

    getmaxyx(stdscr, max_y, max_x); 
    snake = create_snake((max_y - 1) / 2, (max_x - 1) / 2); 


    while (1)
    {
        // -- RENDER -----------------------------------------------------------
        draw_board(); 
        draw_snake(snake);  
        wrefresh(stdscr);

        // -- GAME LOGIC -------------------------------------------------------
        direction = get_dir_from_input(snake);
        change_snake_direction(snake, direction); 
    }

    // -- FREEING THE MEMORY ---------------------------------------------------
    endwin(); 
    free_snake(snake); 
    return 0;
}