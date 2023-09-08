#ifndef CUBED_H
    #define CUBED_H

# include "../libft/libft.h"
# include "lst.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

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

//START
void    run_program(char **argv);

//INPUT
int check_file_input(int fd);
int check_texture(char *line, t_textures **info);
//UTILS

//FILES
int     open_file(char *file);

//MEMORY
t_textures *set_info(void);

#endif
