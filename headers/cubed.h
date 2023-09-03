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

#endif