#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "snake.h"
#include "console.h"
#include "input.h"
#include "food.h"


int main(void) 
{
    int     retval; 
    int     max_x; 
    int     max_y; 
    int     is_running; 

    SNAKE_t *snake; 
    FOOD_t  food; 

    // Initialize the ncurses library. 
    retval = init_console();
    if (retval) 
        return 1; 

    srand(time(NULL)); 

    // Create the snake. 
    getmaxyx(stdscr, max_y, max_x); 
    snake = create_snake((max_x - 1) / 2, (max_y - 1) / 2); 

    set_food_pos(&food); 
    
    // __ MAIN LOOP ____________________________________________________________
    is_running = 1; 
    while (is_running)
    {
        // __ RENDER ___________________________________________________________
        draw_board(); 
        draw_score(snake);

        draw_snake(snake); 
        draw_food(&food); 

        wrefresh(stdscr);

        // __ GAME LOGIC _______________________________________________________
        change_snake_direction(snake, get_dir_from_input()); 
        
        if (snake_body_collision(snake))
            is_running = 0; 

        if (check_snake_collision(snake, &food))
        {
            set_food_pos(&food); 
            retval = append_body(snake, (snake->bodies + snake->len - 1)->x, (snake->bodies + snake->len - 1)->x); 

            if (retval)
            {
                endwin();
                return 1; 
            }
        }
    }

    // __ FREEING MEMORY _______________________________________________________
    endwin(); 
    free_snake(snake); 
    return 0;
}