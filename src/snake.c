#include "snake.h"

SNAKE_t* create_snake(int x, int y)
{
    /*
     * Create and return a SNAKE_t pointer. 
     * param: x: the x position that the snake will spawn.
     * param: y: the y position that the snake will spawn. 
     */

    SNAKE_t     *snake; 
    BODY_t      *bodies; 
    int         i; 

    snake = malloc(sizeof(SNAKE_t));
    bodies = malloc(sizeof(BODY_t) * START_LEN); 

    if (NULL == snake || NULL == bodies)
        return NULL; 

    // Initialize every body coordinate. 
    for (i = 0; i < START_LEN; i++)
    {
        (bodies + i)->x = x; 
        (bodies + i)->y = y + i; 
    }

    snake->len = START_LEN; 
    snake->bodies = bodies; 
    snake->direction = UP; 

    return snake; 
}

void free_snake(SNAKE_t *snake)
{
    /*
     * free all the heap memory taken by the snake and its bodies.  
     * param: snake: the snake that need to be freed. 
     */
    free(snake->bodies); 
    free(snake); 
}


void draw_snake(SNAKE_t* snake)
{
    /*
     * Draw the snake on the console window. 
     * param: snake: the snake to draw. 
     */
    
    size_t  i; 
    size_t  tail_index; 

    tail_index = snake->len - 1; 

    for (i = 0; i < snake->len - 1; i++)
        mvwaddch(stdscr, (snake->bodies + i)->y, (snake->bodies + i)->x, SNAKE_CHAR); 
    
    // Clear the tail. 
    mvwaddch(stdscr, (snake->bodies + tail_index)->y, (snake->bodies + tail_index)->x, ' '); 

    return; 
}


int append_body(SNAKE_t *snake, int x, int y)
{
    /*
     * Append a body part at the end of the snake. 
     * param: snake: the snake that the body part will be appended. 
     */

    BODY_t  *tail;
    BODY_t  *new_bodies; 

    tail = malloc(sizeof(BODY_t));
    if (NULL == tail)
        return 1; 

    tail->x = x; 
    tail->y = y; 

    snake->len += 1; 

    new_bodies = realloc(snake->bodies, snake->len * sizeof(BODY_t)); 
    if (NULL == new_bodies)
        return 1; 

    new_bodies[snake->len - 1] = *tail; 
    snake->bodies = new_bodies; 
    return 0; 
}


void change_snake_direction(SNAKE_t *snake, int new_dir)
{
    /*
     * Change the direction of the snake and move it to the direction passed
     * in argument. Also check if the direction change is allowed. (for example, 
     * it's impossible to change from UP to DOWN). 
     * param: *snake: the snake to update. 
     * param: new_dir: the new direction that need to be checked.  
     */
    switch (new_dir)
    {
    case UP:
        if (snake->direction != DOWN)
            snake->direction = UP; 
        break;
    
    case DOWN:
        if (snake->direction != UP)
            snake->direction = DOWN; 
        break;

    case LEFT:
        if (snake->direction != RIGHT)
            snake->direction = LEFT; 
        break;

    case RIGHT:
        if (snake->direction != LEFT)
            snake->direction = RIGHT; 
        break;
    }

    // Move the snake. 
    update_xy_coord(snake); 
    return; 
}


void update_xy_coord(SNAKE_t *snake)
{
    /*
     * Update the x and y coordinate of the head and all bodies following. 
     * param: snake: the snake will be moved. 
     */

    int     tmp_x;  
    int     tmp_y;  
    int     next_x; 
    int     next_y; 
    size_t  i; 

    find_next_xy(snake, &tmp_x, &tmp_y); 


    for (i = 0; i < snake->len; i++)
    {
        // Update each body part coordinate according to the boby part before.  
        next_x = (snake->bodies + i)->x; 
        next_y = (snake->bodies + i)->y; 

        (snake->bodies + i)->x = tmp_x; 
        (snake->bodies + i)->y = tmp_y; 

        tmp_x = next_x; 
        tmp_y = next_y; 
    }

    return; 
}


void find_next_xy(SNAKE_t *snake, int *new_x, int *new_y)
{
    /*
     * Find the next x and y conforming to the snake direction. 
     * param: snake: 
     * param: *new_x: pointer to the temp variable 
     * param: *new_y: pointer 
     */
    int border_x; 
    int border_y; 

    switch (snake->direction)
    {
    case UP:
        *new_x = snake->bodies->x;
        *new_y = snake->bodies->y - 1;
        break; 
    
    case DOWN:
        *new_x = snake->bodies->x;
        *new_y = snake->bodies->y + 1;
        break; 

    case LEFT:
        *new_x = snake->bodies->x - 1; 
        *new_y = snake->bodies->y;
        break; 
    
    case RIGHT:
        *new_x = snake->bodies->x + 1; 
        *new_y = snake->bodies->y;
        break; 
    }

    getmaxyx(stdscr, border_y, border_x);

    // Check if the head position is outside of the board boundaries. If so
    // Move the snake head to the other side of the board. 
    if (*new_x > border_x - 2)
        *new_x = 1; 

    else if (*new_x <= 0)
        *new_x = border_x - 2; 

    if (*new_y > border_y - 2)
        *new_y = 1; 

    else if (*new_y <= 0)
        *new_y = border_y - 2; 
}


int snake_body_collision(SNAKE_t *snake)
{
    /*
     * Check if the head has collided with a body part. 
     */
    
    int head_x; 
    int head_y; 
    size_t i; 

    head_x = snake->bodies->x; 
    head_y = snake->bodies->y; 

    // Check for every body that compose the snake if it has the same 
    // coordinate of the snake head. 
    for (i = 1; i < snake->len - 1; i++)
    {
        if ((snake->bodies + i)->x == head_x && (snake->bodies + i)->y == head_y)
            return 1; 
    }

    return 0; 
}