#include "food.h"


void set_food_pos(FOOD_t *food)
{
    /*
     * Set the position of the food randomly on the board. 
     * param: *food: the food that need to be placed. 
     */

    int x; 
    int y; 
    int x_border; 
    int y_border; 

    getmaxyx(stdscr, y_border, x_border); 
    x = rand() % (x_border - 2) + 1; 
    y = rand() % (y_border - 2) + 1; 

    food->x = x; 
    food->y = y; 
    return; 
}

int check_snake_collision(SNAKE_t *snake, FOOD_t *food)
{
    /*
     * Check if there is a collision between the head of the snake and the food. 
     * return: 1 if there is a colision, 0 otherwise. 
     */
    return (snake->bodies->x == food->x && snake->bodies->y == food->y);
}

void draw_food(FOOD_t *food) 
{
    mvwaddch(stdscr, food->y, food->x, FOOD_CHAR); 
    return; 
}