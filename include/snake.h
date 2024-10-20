#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <stdlib.h>
#include <ncurses.h>

// __ DEFINITIONS ______________________________________________________________
#define SNAKE_CHAR  '@'
#define UP          0
#define DOWN        1
#define LEFT        2
#define RIGHT       3

#define START_LEN   10

// __ TYPEDEFS _________________________________________________________________
typedef struct Body 
{
    int x;
    int y; 
} BODY_t;


typedef struct Snake 
{
    size_t  len; 
    int     direction; 
    BODY_t  *bodies; 
} SNAKE_t;

// __ FUNCTIONS ________________________________________________________________
// * Create and return a SNAKE_t pointer. 
// * @param: x: the x position that the snake will spawn.
// * @param: y: the y position that the snake will spawn. 
// * @return: the newly created snake. 
SNAKE_t*    create_snake(int x, int y); 

// * free all the heap memory taken by the snake and its bodies.  
// * @param: snake: the snake that need to be freed. 
void        free_snake(SNAKE_t *snake); 

// * Draw the snake on the console window. 
// * @param: snake: the snake to draw. 
void        draw_snake(SNAKE_t* snake); 

// * Append a body part at the end of the snake. 
// * @param: snake: the snake that the body part will be appended. 
// * @return: 0 if no error occured, 1 otherwise. 
int         append_body(SNAKE_t *snake, int x, int y);

// * Change the direction of the snake and move it to the direction passed
// * in argument. Also check if the direction change is allowed. (for example, 
// * it's impossible to change from UP to DOWN). 
// * @param: *snake: the snake to update. 
// * @param: new_dir: the new direction that need to be checked.  
void        change_snake_direction(SNAKE_t *snake, int new_dir); 

// * Update the x and y coordinate of the head and all bodies following. 
// * @param: snake: the snake will be moved. 
void        find_next_xy(SNAKE_t *snake, int *new_x, int *new_y); 

// * Find the next x and y conforming to the snake direction. 
// * @param: snake: the snake will be moved. 
// * @param: *new_x: pointer to the temp variable 
// * @param: *new_y: pointer 
void        update_xy_coord(SNAKE_t *snake); 

// * Check if the head has collided with a body part. 
// * @param: *snake: the snake that need to be checked. 
// * @return: 1 if there is a collision with the snake body, 0 otherwise. 
int         snake_body_collision(SNAKE_t *snake); 
#endif