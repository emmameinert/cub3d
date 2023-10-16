
#include "../../headers/cubed.h"

static t_texture	*get_texture(t_info **info, t_ray *ray)
{
	if (ray->wall_color == NO)
		return ((*info)->no);
	if (ray->wall_color == SO)
		return ((*info)->so);
	if (ray->wall_color == WE)
		return ((*info)->we);
	return ((*info)->ea);
}

static void	get_wall_info(t_info **info, int i, int is_vertical)
{
	t_ray		*ray;
	t_texture	*text;

	ray = &(*info)->rays[i];
	text = get_texture(info, ray);
	if (is_vertical)
	{
		if (ray->angle < 90 || (ray->angle > 270 && ray->angle < 360))
			ray->wall_color = WE;
		else if (ray->angle > 90 && ray->angle < 270)
			ray->wall_color = EA;
		ray->text_x = (int)(ray->y * text->width / GRID_SIZE) % text->width;
		return ;
	}
	if (ray->angle < 180)
		ray->wall_color = SO;
	else
		ray->wall_color = NO;
	ray->text_x = (int)(ray->x * text->width / GRID_SIZE) % text->width;
}

static int	wall_hit(t_info **info, int i, int is_vertical)
{
	static int	increment_x;
	int	increment_y;

	increment_y = (int)floor((*info)->rays[i].y / GRID_SIZE);
	if (is_vertical)
		increment_x = (int)floor((*info)->rays[i].x / GRID_SIZE);
	if (increment_x >= (*info)->m_width || increment_x < 0 || (*info)->map[increment_y][increment_x].ch == ' ')
		return (1);
	else if (increment_y >= (*info)->m_height || increment_y < 0 || (*info)->map[increment_y][increment_x].ch == ' ')
		return (1);
	if ((*info)->map[increment_y][increment_x].ch == '1')
	{
		get_wall_info(info, i, is_vertical);
		return (1);
	}
	return (0);
}

static double	get_angle(t_info **info, int i)
{
	if (i == 0)
		return (ft_angle((*info)->player->angle + ((*info)->player->fov / 2)));
	else
		return (ft_angle((*info)->rays[i - 1].angle - (*info)->player->ray_increment));
}

void	cast_rays(t_info **info)
{
	double	cos_inc;
	double	sin_inc;
	int		i;

	i = -1;
	cos_inc = 0.0;
	sin_inc = 0.0;
	while (++i < WIN_WIDTH)
	{
		init_ray(get_angle(info, i), &(*info)->rays[i], (*info)->player);
		cos_inc = cos(ft_dtorad((*info)->rays[i].angle)) / 192;
		sin_inc = -sin(ft_dtorad((*info)->rays[i].angle)) / 192;
		while (1) // check for wall hit
		{
			(*info)->rays[i].x += cos_inc;
			if (wall_hit(info, i, 1))
				break ;
			(*info)->rays[i].y += sin_inc;
			if (wall_hit(info, i, 0))
				break ;
		}
	}
}
