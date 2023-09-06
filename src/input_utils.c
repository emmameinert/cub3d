#include "../headers/cubed.h"

static void    set_colors(t_color **color)
{
    (*color)->r = -2;
    (*color)->g = -2;
    (*color)->b = -2;
}

t_textures *set_info(void)
{
    t_textures *info;

    info = ft_calloc(1, sizeof(*info));
    if (!info)
    {
        ft_putstr_fd("Error with allocation\n", 2);
        exit(1);
    }
    info->no = -2;
    info->so = -2;
    info->ea = -2;
    info->we = -2;
    info->ceiling = ft_calloc(1, sizeof(t_color));
    info->floor = ft_calloc(1, sizeof(t_color));
    set_colors(&(info->ceiling));
    set_colors(&(info->floor));
    return (info);
}

int     open_file(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
	// if (fd == -1)
	// 	exit(1);
	return (fd);
}