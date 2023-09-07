
#include "../headers/cubed.h"

static int if_no_line(int counter)
{
    if (counter < 6) //makes sure we are not missing information
    {
        ft_putstr_fd("Error with missing input\n", 2);
        return (1);
    }
    //check_map
    //check if valid (surrounded by walls) maybe flood fill algo
    return (0);
}

/// @brief runs through the file and checks for all needed information and the map
/// @param fd from our map file
/// @return
int check_file_input(int fd) //parse_validate_input
{
    char *line;
    int counter;
    t_data *info;

    info = set_info();
    counter = 0;
    while (fd > 1)
	{
		line = get_next_line(fd);
		if (!line)
            return(if_no_line(counter));
        printf("line: %s\n", line);
        if (counter < 6)
            check_texture(line, &info, &counter);
        printf("counter main: %d\n", counter);
        // if (!ft_isdigit(line[0]) || line[0] == 32)
        //     add_map(line, &info);
        //needs a check, that the map is the last thing in the file
		free(line);
	}
    printf("all good\n");
    return (0);
}

//maybe seprate functions into the counter and texture and parsin/validating map


