
#include "../../headers/cubed.h"

static void	init_rgb(t_color **color)
{
	(*color)->r = -2;
	(*color)->g = -2;
	(*color)->b = -2;
}

static void	init_textures(t_info **info)
{
	(*info)->no = -2;
	(*info)->so = -2;
	(*info)->ea = -2;
	(*info)->we = -2;
}

static void	init_colors(t_info **info)
{
	(*info)->ceiling = ft_calloc(1, sizeof(t_color));
	(*info)->floor = ft_calloc(1, sizeof(t_color));
	init_rgb(&((*info)->ceiling));
	init_rgb(&((*info)->floor));
}

static void	init_player(t_info **info)
{
	(*info)->player = ft_calloc(1, sizeof(t_player));
	(*info)->player->x = -2;
	(*info)->player->y = -2;
}

t_info	*init_info(void)
{
	t_info	*info;

	info = ft_calloc(1, sizeof(*info));
	init_player(&info);
	init_colors(&info);
	init_textures(&info);
	info->m_width = 0;
	info->m_height = 0;
	info->y_index = 0;
	info->x_index = 0;
	return (info);
}
