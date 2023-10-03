
#include "../../headers/cubed.h"

static double	calculate_wallheight(double distance)
{
	double height;

	height = floor((WIN_HEIGHT / 2) / distance);
	return (height);
}

static double	calculate_distance(t_info **info, t_ray ray)
{
	double dist;

	dist = sqrt(pow((*info)->player->x - ray.x, 2) + pow((*info)->player->y - ray.y, 2)) * 0.175;
	dist = dist * cos(ft_dtorad(ray.angle - (*info)->player->angle)); // fish eye fix
	return (dist);
}

void	draw_ceiling(t_info **info, double half_wallheight, int x)
{
	t_coord	from;
	t_coord	to;

	from.y = 0;
	to.y = (WIN_HEIGHT / 2) - half_wallheight;
	from.x = x;
	to.x = x;
	draw_line(info, &from, &to, (*info)->ceiling->draw_color);
}

void	draw_wall(t_info **info, double half_wallheight, int x)
{
	t_coord	from;
	t_coord	to;

	from.y = (WIN_HEIGHT / 2) - half_wallheight;
	to.y = (WIN_HEIGHT / 2) + half_wallheight;
	from.x = x;
	to.x = x;
	draw_line(info, &from, &to, (*info)->rays[x].wall_color);
}

void	draw_floor(t_info **info, double half_wallheight, int x)
{
	t_coord	from;
	t_coord	to;

	from.y = (WIN_HEIGHT / 2) + half_wallheight;
	to.y = WIN_HEIGHT;
	from.x = x;
	to.x = x;
	draw_line(info, &from, &to, (*info)->floor->draw_color);
}

void	draw_screen(t_info **info, int x)
{
	t_coord	from;
	t_coord	to;

	from.y = 0;
	to.y = WIN_HEIGHT;
	from.x = x;
	to.x = x;
	draw_line(info, &from, &to, COLOR_GRAY);
}

void	draw_maze(t_info **info)
{
	int		i;
	double	dist;
	double	half_wallheight;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		dist = calculate_distance(info, (*info)->rays[i]);
		if (dist < 1)
		{
			draw_screen(info, i);
			continue ;
		}
		half_wallheight = calculate_wallheight(dist);
		draw_ceiling(info, half_wallheight, i);
		draw_wall(info, half_wallheight, i);
		draw_floor(info, half_wallheight, i);
	}
}
