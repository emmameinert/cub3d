
#include "../headers/cubed.h"

void run_program(char **argv)
{
    int fd;

    suffix_cmp(argv[1], ".cub");
    fd = open_file(argv[1]);
    validate_parse_file(fd);
    close(fd);
}
