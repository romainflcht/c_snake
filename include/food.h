#ifndef _FOOD_H_
#define _FOOD_H_

#include <stdlib.h>
#include <snake.h>

// __ DEFINITIONS ______________________________________________________________
#define FOOD_CHAR  'O'

// __ TYPEDEFS _________________________________________________________________
typedef struct Food 
{
    int x; 
    int y; 
} FOOD_t;

// __ FUNCTIONS ________________________________________________________________
// * Set the position of the food randomly on the board. 
// * @param: *food: the food that need to be placed. 
void set_food_pos(FOOD_t *food); 

// * Check if there is a collision between the head of the snake and the food. 
// * @param: *snake: the snake that need to be checked. 
// * @param: *food: the food that need to be checked. 
// * @return: 1 if there is a colision, 0 otherwise. 
int check_snake_collision(SNAKE_t *snake, FOOD_t *food); 
void draw_food(FOOD_t *food);

#endif