#ifndef CUBED_H
    #define CUBED_H

#include "../libft/libft.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"

void    run_program(char **argv);


typedef struct s_data
{
    int no;
    int so;
    int ea;
    int we;
    char *ceiling;
    char *floor;
}	t_data;

/// @brief coordinates for x y and z can be either our value (1/0) or our later calculated altitude
typedef struct s_coord
{
    int x;
    int y;
    int z;
}   t_coord;

///linked list for our map grid
typedef struct s_map
{
    t_coord    *current;
    struct s_map *next;
}   t_map;

#endif