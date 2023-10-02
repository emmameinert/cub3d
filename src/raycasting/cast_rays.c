
#include "../../headers/cubed.h"

static int	wall_hit(t_ray *ray, t_info **info)
{
	int	increment_x;
	int	increment_y;

	increment_y = (int)floor(ray->y / GRID_SIZE);
	increment_x = (int)floor(ray->x / GRID_SIZE);
	if (increment_x >= (*info)->m_width || increment_x < 0)
		return (1);
	else if (increment_y >= (*info)->m_height || increment_y < 0)
		return (1);
	if ((*info)->map[increment_y][increment_x].ch == '1')
		return (1);
	return (0);
}

void	init_ray(t_ray *ray, t_player *player, double angle)
{
	ray->angle = ft_angle(angle);
	ray->x = player->x;
	ray->y = player->y;
	ray->cos = 0;
	ray->sin = 0;
}

void	cast_rays(t_info **info)
{
	int		i;
	double	angle;
	t_ray	ray;

	i = -1;
	angle = (*info)->player->angle - ((*info)->player->fov / 2); // start from -30 degrees from the player direction
	while (++i < 1) // increment ray
	{
		init_ray(&ray, (*info)->player, angle);
		ray.cos = cos(ft_dtorad(ray.angle)) / 64; // calculate the x increment
		ray.sin = -sin(ft_dtorad(ray.angle)) / 64; // calculate the y increment
		while (!wall_hit(&ray, info)) // check for wall hit
		{
			ray.x += ray.cos;
			ray.y += ray.sin;
		}
		draw_rays(info, &ray);
	}
}