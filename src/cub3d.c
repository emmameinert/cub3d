#include "../headers/cubed.h"

void run_program(char **argv)
{
    int fd;

    if (ft_strncmp(argv[0], "./cub3D", 7))
    {
        ft_putstr_fd("Error with executable\n", 2);
        exit(1);
    }
    fd = open_file(argv[1]);
    if (check_file_input(fd))
    {
        ft_putstr_fd("Error with testfile\n", 2);
        exit(1);
    }
    //create_window
}