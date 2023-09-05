#include "../headers/cubed.h"

/// @brief checks if we have information about the textures floor or cealing
/// @param line line of the file we are reading
/// @param info here we save our general information about the map
int check_texture(char *line, t_data **info, int *counter)
{
    char **input;

//need to check if files can be opened and if the colors are in range
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
int    check_data(t_data **info, int *counter)
{
    if (!(*info)->no)
        *counter = *counter - 1;
    if (!(*info)->so)
        *counter = *counter - 1;
    if (!(*info)->ea)
        *counter = *counter - 1;
    if (!(*info)->we)
        *counter = *counter - 1;
    if (!(*info)->ceiling)
        *counter = *counter - 1;
    if (!(*info)->floor)
        *counter = *counter - 1;
    return (*counter);
}