#include "../headers/cubed.h"

static void if_no_line(int counter)
{
    if (counter < 6) //makes sure we are not missing information
        ft_put_error_exit("Error with missing textures");
    //check_map
    //check if valid (surrounded by walls) maybe flood fill algo
}
/// @brief runs through the file and checks for all needed information and the map
/// @param fd from our map file
/// @return 
void validate_parse_file(int fd) 
{
    char *line;
    int counter;
    t_textures *info;

    info = set_info();
    counter = 0;
    while (fd > 1)
	{
		line = get_next_line(fd);
		if (!line)
            if_no_line(counter);
        if (counter < 6)
            counter += check_texture(line, &info);
        printf("counter main: %d\n", counter);
        //check for garbageeeee
        // if (!ft_isdigit(line[0]) || line[0] == 32)
        //     add_map(line, &info);
        //needs a check, that the map is the last thing in the file
		free(line);
	}
}

//maybe seprate functions into the counter and texture and parsin/validating map


