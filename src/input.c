#include "../headers/cubed.h"

static int if_no_line(int counter)
{
    if (counter < 6) //makes sure we are not missing information
    {
        ft_putstr_fd("Error with missing input\n", 2);
        return (1);
    }
    //check_map
    return (0);
}

// static  void    add_map(char *line, t_data **info)
// {
//     //add to linked list
//     //check for characters
//     //check if valid (surrounded by walls)

// }

/// @brief runs through the file and checks for all needed information and the map
/// @param fd from our map file
/// @return 
int check_file_input(int fd)
{
    char *line;
    int counter;
    t_data *info;

    info = set_info();
    counter = 0;
    while (fd != 0)
	{
		line = get_next_line(fd);
        if (counter < 6)
            counter += check_texture(line, &info, &counter);
        else
            counter = check_data(&info, &counter); //checks we dont have double information and missing one
        // if (!ft_isdigit(line[0]) || line[0] == 32)
        //     add_map(line, &info);
        //needs a check, that the map is the last thing in the file
		if (!line)
            return(if_no_line(counter));
		free(line);
	}
    return (0);
}


