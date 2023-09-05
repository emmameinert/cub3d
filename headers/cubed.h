#ifndef CUBED_H
    #define CUBED_H

# include "../libft/libft.h"
# include "lst.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_data
{
    int no;
    int so;
    int ea;
    int we;
    char *ceiling;
    char *floor;
}	t_data;

typedef struct t_coord;

//START
void    run_program(char **argv);

//INPUT
int check_file_input(int fd);
int check_texture(char *line, t_data **info, int *counter);
int check_data(t_data **info, int *counter);
//UTILS

int     open_file(char *file);
t_data *set_info(void);

#endif
