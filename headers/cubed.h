#ifndef CUBED_H
    #define CUBED_H

#include "../libft/libft.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "../mlx/mlx.h"

typedef struct s_color
{
    int r;
    int g;
    int b;
}   t_color;

typedef struct s_textures
{
    int no;
    int so;
    int ea;
    int we;
    t_color *ceiling;
    t_color *floor;
}	t_textures;

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

//START
void    run_program(char **argv);

//INPUT
int check_file_input(int fd);
int check_texture(char *line, t_textures **info, int *counter);
//UTILS

//FILES
int     open_file(char *file);

//MEMORY
t_textures *set_info(void);

#endif