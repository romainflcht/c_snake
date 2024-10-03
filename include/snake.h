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
    BODY_t  *bodies; 
    int     direction; 
} SNAKE_t;


// __ FUNCTIONS ________________________________________________________________
SNAKE_t*    create_snake(int x, int y); 
void        free_snake(SNAKE_t *snake); 
void        draw_snake(SNAKE_t* snake); 
int         append_body(SNAKE_t *snake, int x, int y);
void        change_snake_direction(SNAKE_t *snake, int new_dir); 
void        find_next_xy(SNAKE_t *snake, int *new_x, int *new_y); 
void        update_xy_coord(SNAKE_t *snake); 
int         snake_body_collision(SNAKE_t *snake); 
#endif