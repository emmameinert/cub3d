
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

	dist = sqrt(pow((*info)->player->x - ray.x, 2) + pow((*info)->player->y - ray.y, 2));
	dist = dist * cos(ft_dtorad(ray.angle - (*info)->player->angle)); // fish eye fix
	return (dist);
}

void	draw_ceiling(t_info **info, t_ray ray, double half_wallheight, int color)
{
	t_coord	from;
	t_coord	to;
	int		i;

	from.y = 0;
	to.y = (WIN_HEIGHT / 2) - half_wallheight * GRID_SIZE;
	i = -1;
	while (++i < 10)
	{
		from.x = ray.x + WIN_WIDTH / 2 + i;
		to.x = ray.x + WIN_WIDTH / 2 + i;
		draw_line(info, &from, &to, color);
	}
}

void	draw_maze(t_info **info, t_ray ray)
{
	double	dist;
	double	half_wallheight;

	dist = calculate_distance(info, ray);
	// printf("distance to wall %f\n", dist);
	half_wallheight = calculate_wallheight(dist);
	// printf("wall height %f\n", half_wallheight);
	draw_ceiling(info, ray, half_wallheight, (*info)->ceiling->draw_color);
	// draw_wall(ray, (WIN_HEIGHT / 2) - half_wallheight, (WIN_HEIGHT / 2) + half_wallheight, COLOR_GRAY);
	// draw_floor(ray, (WIN_HEIGHT / 2) + half_wallheight, WIN_HEIGHT, (*info)->floor);
}