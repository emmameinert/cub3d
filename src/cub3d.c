#include "../headers/cubed.h"

void run_program(char **argv)
{
    int fd;

    fd = open_file(argv[1]);
    if (check_file_input(fd))
    {
        ft_putstr_fd("Error with testfile\n", 2);
        exit(1);
    }
    close(fd);
    exit(0);
    //create_window
}