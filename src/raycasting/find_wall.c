
#include "../../headers/cubed.h"

static int	wall_hit(int pos, t_info **info)
{
	if(pos > 0 && pos < (*info)->m_width * (*info)->m_height
		&& (*info)->map[pos / (*info)->m_width][pos % (*info)->m_width].ch == '1')
			return (1);
	return (0);
}

static double	calc_dist(t_info **info)
{
	return (cos(ft_dtorad((*info)->ray->angle)) * ((*info)->ray->x - (*info)->player->x)
		- sin(ft_dtorad((*info)->ray->angle)) * ((*info)->ray->y - (*info)->player->y));
}

int	find_wall(t_info **info, int map_size)
{
	t_map	map;
	int 	dov;
	int		dist;

	if ((*info)->ray->x == (*info)->player->x
		&& (*info)->ray->y == (*info)->player->y)
		dov = map_size;
	else
		dov = 0;
	while (dov < map_size)
	{
		map.x = (int)((*info)->ray->x / GRID_SIZE);
		map.y = (int)((*info)->ray->y / GRID_SIZE);
		map.pos = map.y * (*info)->m_width + map.x;
		if (wall_hit(map.pos, info))
		{
			dist = calc_dist(info);
			return dist;
		}
		(*info)->ray->x += (*info)->ray->x_offset;
		(*info)->ray->y += (*info)->ray->y_offset;
		dov++;
	}
	return ((*info)->m_width);
}
