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
void set_food_pos(FOOD_t *food); 
int check_snake_collision(SNAKE_t *snake, FOOD_t *food); 
void draw_food(FOOD_t *food);
#endif