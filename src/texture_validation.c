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
        if (colour[i] < 0 || colour[i] > 255)
           break ;
        i++;
    }
    free_char_array(numbers);
    if (i != 3) 
        ft_put_error_exit("Wrong color");
    color->r = colour[0];
    color->g = colour[1];
    color->b = colour[2];
}

static  int    parse_floor_ceiling(char **input, t_textures **info)
{
    if (input[0][0] == 'F')
    {
        if ((*info)->floor->r != -2)
            ft_put_error_exit("Floor duplicate");
        check_parse_range(input[1], (*info)->floor);
    }
    else if (!ft_strncmp_all(input[0], "C"))
    {
        if ((*info)->ceiling->r != -2)
            ft_put_error_exit("Ceiling duplicate");
        check_parse_range(input[1], (*info)->ceiling);
    }
    else 
        return (0);
    return (1);
}

static  void    texture_existence(int fd, char *msg)
{
    if (fd != -2)
        ft_put_error_exit(msg);
}

static int texture_comparison(char **input, t_textures **info)
{
    if (!ft_strncmp_all(input[0], "NO"))
    {
        texture_existence((*info)->no, "NO Texture duplicate");
        (*info)->no = open_file(input[1]);
    }
    else if (!ft_strncmp_all(input[0], "SO"))
    {
        texture_existence((*info)->so, "SO Texture duplicate");
        (*info)->so = open_file(input[1]);
    }
    else if (!ft_strncmp_all(input[0], "EA"))
    {
        texture_existence((*info)->ea, "EA Texture duplicate");
        (*info)->ea = open_file(input[1]);
    }
    else if (!ft_strncmp_all(input[0], "WE"))
    {
        texture_existence((*info)->we, "WE Texture duplicate");
        (*info)->we = open_file(input[1]);
    }
    else
        return (0);
    return (1);
}
/// @brief checks if we have information about the textures floor or cealing
/// @param line line of the file we are reading
/// @param info here we save our general information about the map
int    check_texture(char *line, t_textures **info)
{
    char **input;

    input = ft_split(line, 32);
    if (!input)
        ft_put_error_exit("Allocation failed");
    if (!texture_comparison(input, info))
    {
        if (!parse_floor_ceiling(input, info))
        {
            free_char_array(input);
            return (0);
        }
    }
    free_char_array(input);
    return (1);
}
