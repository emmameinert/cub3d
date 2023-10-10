
#include "../../headers/cubed.h"

static double	calculate_wallheight(double distance)
{
	double height;

	height = floor((WIN_HEIGHT / 2) / distance);
	return (height);
}

static double	calc_wall_dist(t_info **info, t_ray ray)
{
	double dist;

	dist = sqrt(pow((*info)->player->x - ray.x, 2) + pow((*info)->player->y - ray.y, 2)) * 0.175;
	dist = dist * cos(ft_dtorad(ray.angle - (*info)->player->angle)); // fish eye fix
	return (dist);
}

static void	draw_on_y(t_info **info, double half_wallheight, int x)
{
	draw_ceiling(info, half_wallheight, x);
	draw_wall(info, half_wallheight, &(*info)->rays[x]);
	draw_floor(info, half_wallheight, x);
}

void	draw_maze(t_info **info)
{
	int		i;
	double	dist;
	double	half_wallheight;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		dist = calc_wall_dist(info, (*info)->rays[i]);
		if (dist < 1)
		{
			draw_screen(info, i);
			continue ;
		}
		half_wallheight = calculate_wallheight(dist);
		draw_on_y(info, half_wallheight, i);
	}
}
