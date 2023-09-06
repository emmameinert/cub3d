#include "../headers/cubed.h"

void ft_put_error_exit(char *msg)
{
    ft_putstr_fd("Error\n", 2);
    ft_putendl_fd(msg, 2);
    exit(1);
}
/// @brief checks for integers in range and returns the correct one
/// @param input 
/// @return 
static  void check_parse_range(char *input, t_color *color)
{
    char **numbers;
    int i;
    int colour[3];

    numbers = ft_split(input, ',');
    i = 0;
    while (numbers[i] && i < 3)
    {
        colour[i] = ft_atoui(numbers[i]);
        if (colour < 0 || colour > 255)
           break ;
        i++;
    }
    free_char_array(numbers);
    if (i != 2) 
        ft_put_error_exit("Wrong colour");
    color->r = colour[0];
    color->g = colour[1];
    color->b = colour[2];
}

/// @brief checks if we have information about the textures floor or cealing
/// @param line line of the file we are reading
/// @param info here we save our general information about the map
int    check_texture(char *line, t_textures **info)
{
    char **input;

    input = ft_split(line, 32);
    if ((*info)->no == 0 && !ft_strncmp_all(input[0], "NO"))
        (*info)->no = open_file(input[1]);
    else if ((*info)->so == 0 && !ft_strncmp_all(input[0], "SO"))
        (*info)->so = open_file(input[1]);
    else if ((*info)->ea == 0  && !ft_strncmp_all(input[0], "EA"))
        (*info)->ea = open_file(input[1]);
    else if ((*info)->we == 0 && !ft_strncmp_all(input[0], "WE"))
        (*info)->we = open_file(input[1]);
    else if (!ft_strncmp_all(input[0], "F"))
    {
        printf("floor check before: %d\n", (*info)->floor->r);
        check_parse_range(input[1], (*info)->floor);
        printf("floor check after : %d\n", (*info)->floor->r);
    }
    else if (!ft_strncmp_all(input[0], "C"))
        check_parse_range(input[1], (*info)->ceiling);
    else 
    {
        printf("input[0]: '%s'\n", input[0]);
        free_char_array(input);
        return (0);
    }
    free_char_array(input);
    return (1);
}
