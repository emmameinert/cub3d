#include "../headers/cubed.h"

static  t_data *set_info(void)
{
    t_data *info;

    info = ft_calloc(1, sizeof(info));
    return (info);
}
/// @brief checks if we have information about the textures floor or cealing
/// @param line line of the file we are reading
/// @param info here we save our general information about the map
static int check_texture(char *line, t_data **info, int *counter)
{
    char **input;

    input = ft_split(line, 32);
    if (!ft_strncmp(input[0], "NO", 2))
        (*info)->no = open(input[1], O_RDONLY);
    else if (!ft_strncmp(input[0], "SO", 2))
        (*info)->so = open(input[1], O_RDONLY);
    else if (!ft_strncmp(input[0], "EA", 2))
        (*info)->ea = open(input[1], O_RDONLY);
    else if (!ft_strncmp(input[0], "WE", 2))
        (*info)->we = open(input[1], O_RDONLY);
    else if (!ft_strncmp(input[0], "F", 1))
        (*info)->floor = ft_strdup(input[1]);
    else if (!ft_strncmp(input[0], "C", 1))
        (*info)->ceiling = ft_strdup(input[1]);
    else
        return(*counter);
    return (*counter + 1); //checks now if we have all information, doesnt check if we have one twice and missing another one
    free_char_array(input);
}
/// @brief checks if all necessary information has been added to out struct
/// @param info 
/// @param counter 
/// @return 
static  int    check_data(t_data **info, int *counter)
{
    if (!(*info)->no)
        *counter--;
    if (!(*info)->so)
        *counter--;
    if (!(*info)->ea)
        *counter--;
    if (!(*info)->we)
        *counter--;
    if (!(*info)->ceiling)
        *counter--;
    if (!(*info)->floor)
        *counter--;
    return (counter);
}

static int input_check(int fd)
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
		if (!line)
		{
            if (counter < 6) //makes sure we are not missing information
            {
                ft_putstr_fd("Error with missing input\n", 2);
                return (1);
            }
            break ;
        }
		free(line);
	}
    return (0);
}

static int     open_file(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	return (fd);
}

void run_program(char **argv)
{
    int fd;

    if (ft_strncmp(argv[0], "./cub3D", 7))
    {
        ft_putstr_fd("Error with executable\n", 2);
        exit(1);
    }
    fd = open_file(argv[1]);
    if (input_check(fd))
    {
        ft_putstr_fd("Error with testfile\n", 2);
        exit(1);
    }
    //create_window
}

