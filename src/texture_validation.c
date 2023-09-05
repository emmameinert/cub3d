#include "../headers/cubed.h"

/// @brief checks for integers in range and returns the correct one
/// @param input 
/// @return 
static  char **check_parse_range(char *input)
{
    char **numbers;
    int i;
    int j;
    int error_flag;

    numbers = ft_split(input, ',');
    i = -1;
    while (numbers[++i])
    {
        j = -1;
        while (numbers[i][++j])
        {
            if (ft_isdigit(numbers[i][j]))
                error_flag = 1;
        }
        if (ft_atoi(numbers[i]) < 0 || ft_atoi(numbers[i]) > 255)
            error_flag = 1;
    }
    if (error_flag)
    {
        free_char_array(numbers);
        return (NULL);
    }
    return (numbers);
}

/// @brief checks if we have information about the textures floor or cealing
/// @param line line of the file we are reading
/// @param info here we save our general information about the map
int check_texture(char *line, t_data **info, int *counter)
{
    char **input;

    input = ft_split(line, 32);
    if (!(*info)->no && !ft_strncmp_all(input[0], "NO"))
        (*info)->no = open_file(input[1]); //use open_file function here
    else if (!(*info)->so && !ft_strncmp_all(input[0], "SO"))
        (*info)->so = open_file(input[1]);
    else if (!(*info)->ea  && !ft_strncmp_all(input[0], "EA"))
        (*info)->ea = open_file(input[1]);
    else if (! (*info)->we && !ft_strncmp_all(input[0], "WE"))
        (*info)->we = open_file(input[1]);
    else if (!(*info)->floor && !ft_strncmp_all(input[0], "F"))
        (*info)->floor = check_parse_range(input[1]);
    else if (!(*info)->ceiling && !ft_strncmp_all(input[0], "C"))
        (*info)->ceiling = check_parse_range(input[1]);
    else
        *counter--;
    free_char_array(input);
    return (*counter + 1); //checks now if we have all information, doesnt check if we have one twice and missing another one
}