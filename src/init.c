#include "../headers/cubed.h"

static void    init_colors(t_color **color)
{
    (*color)->r = -2;
    (*color)->g = -2;
    (*color)->b = -2;
}

t_textures *init_info(void)
{
    t_textures *info;

    info = ft_calloc(1, sizeof(*info));
    info->no = -2;
    info->so = -2;
    info->ea = -2;
    info->we = -2;
    info->ceiling = ft_calloc(1, sizeof(t_color));
    info->floor = ft_calloc(1, sizeof(t_color));
    init_colors(&(info->ceiling));
    init_colors(&(info->floor));
    return (info);
}
