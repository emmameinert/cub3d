
#include "../../headers/cubed.h"

static void	get_wall_dir(t_ray *ray)
{
	int	mod_y;
	int	mod_x;
	int y;
	int x;

	y = (int)ray->y;
	x = (int)ray->x;
	mod_y = y % 16;
	mod_x = x % 16;
	if (mod_y == 0)
		ray->wall_color = COLOR_GRAY; // NO
	else if (mod_y == 15)
		ray->wall_color = COLOR_GOLD; // SO
	else if (mod_x == 0)
		ray->wall_color = GREEN; // WE
	else if (mod_x == 15)
		ray->wall_color = PINK; // EA
	else
		ray->wall_color = BLACK; // :(
}

static int	wall_hit(t_ray *ray, t_info **info)
{
	int	increment_x;
	int	increment_y;

	increment_y = (int)floor(ray->y / GRID_SIZE);
	increment_x = (int)floor(ray->x / GRID_SIZE);
	if (increment_x >= (*info)->m_width || increment_x < 0 || (*info)->map[increment_y][increment_x].ch == ' ')
		return (1);
	else if (increment_y >= (*info)->m_height || increment_y < 0 || (*info)->map[increment_y][increment_x].ch == ' ')
		return (1);
	if ((*info)->map[increment_y][increment_x].ch == '1')
	{
		get_wall_dir(ray);
		return (1);
	}
	return (0);
}

static void	init_ray(double angle, t_ray *ray, t_player *player)
{
	ray->angle = angle;
	ray->x = player->x;
	ray->y = player->y;
	ray->cos = 0;
	ray->sin = 0;
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
	int		i;

	i = -1;
	 // start from -30 degrees from the player direction
	while (++i < WIN_WIDTH) // increment ray
	{
		init_ray(get_angle(info, i), &(*info)->rays[i], (*info)->player);
		(*info)->rays[i].cos = cos(ft_dtorad((*info)->rays[i].angle)); // / 192; // calculate the x increment
		(*info)->rays[i].sin = -sin(ft_dtorad((*info)->rays[i].angle)); // / 192; // calculate the y increment
		while (!wall_hit(&(*info)->rays[i], info)) // check for wall hit
		{
			(*info)->rays[i].x += ((*info)->rays[i].cos / 192);
			(*info)->rays[i].y += ((*info)->rays[i].sin / 192);
		}
	}
}
