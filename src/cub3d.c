#include "../headers/cubed.h"

void     suffix_cmp(char *file, char *suffix)
{
    int len;
    char *file_ending;
    len = ft_strlen(file);
    if (!ft_strncmp_all(suffix, ".xpm"))
        file_ending = ft_substr(file, len - 5, 4);
    else
        file_ending = ft_substr(file, len - 4, 4);
    if (ft_strncmp_all(file_ending, suffix))
    {
        free(file_ending);
        ft_put_error_exit("Wrong file suffix");
    }
    free(file_ending);
}
void run_program(char **argv)
{
    int fd;

    suffix_cmp(argv[1], ".cub");
    fd = open_file(argv[1]);
    validate_parse_file(fd);
    close(fd);
    exit(0);
    //create_window
}