
#include "../../headers/cubed.h"

static void	init_rgb(t_color **color)
{
	(*color)->r = -2;
	(*color)->g = -2;
	(*color)->b = -2;
}

static void init_texture(t_texture **texture, int type)
{
	(*texture)->fd = -2;
	(*texture)->img = ft_calloc(1, sizeof(t_img));
	(*texture)->type = type;
}

static void	init_textures(t_info **info)
{
	(*info)->no = ft_calloc(1, sizeof(*(*info)->no));
	init_texture(&(*info)->no, NO);
	(*info)->so = ft_calloc(1, sizeof(*(*info)->so));
	init_texture(&(*info)->so, SO);
	(*info)->ea = ft_calloc(1, sizeof(*(*info)->ea));
	init_texture(&(*info)->ea, EA);
	(*info)->we = ft_calloc(1, sizeof(*(*info)->we));
	init_texture(&(*info)->we, WE);
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
	(*info)->player->angle = 60;
	(*info)->player->dir_x = 0;
	(*info)->player->dir_y = 0;
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
	init_mlx(&info);
	return (info);
}
