#include "../headers/cubed.h"

static int validate_missing_input(int counter)
{
    if (counter < 6)
        ft_put_error_exit("Error with missing textures");
    //check_map
    //check if valid (surrounded by walls) maybe flood fill algo
    return (1);
}
/// @brief runs through the file and checks for all needed information and the map
/// @param fd from our map file
/// @return
void validate_parse_file(int fd)
{
    char *line;
    int counter;
    int flag;
    t_textures *info;

    flag = 0;
    info = init_info();
    counter = 0;
    while (!flag)
	{
		line = get_next_line(fd);
		if (!line)
            flag = validate_missing_input(counter);
        if (counter < 6)
            counter += validate_texture(line, &info);
		free(line);
	}
}



