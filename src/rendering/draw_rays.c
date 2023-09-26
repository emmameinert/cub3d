
#include "../../headers/cubed.h"

static void	check_horizontal(t_info **info)
{
	t_ray	ray;
	t_map	map;
	t_coord from;
	t_coord to;
	double	angleTan;
	int		depth_of_field;
	int		i;

	i = 0;
	depth_of_field = 0;
	ray.angle = ft_angle((*info)->player->angle + (*info)->player->fov_angle / 2);
	ray.sin = sin(ft_dtorad(ray.angle));
	while (i < 1)
	{
		angleTan = 1 / tan(ft_dtorad(ray.angle));
		if (ray.sin > 0.001) // looking up
		{
			ray.y = ((*info)->player->y / GRID_SIZE * GRID_SIZE) - 0.0001;
			ray.x = ((*info)->player->x - ray.y) * angleTan + (*info)->player->x;
			ray.y_offset = -GRID_SIZE;
			ray.x_offset = -ray.y_offset * angleTan;
		}
		if (ray.sin < -0.001) // looking down
		{
			ray.y = ((*info)->player->y / GRID_SIZE * GRID_SIZE) + GRID_SIZE;
			ray.x = ((*info)->player->x - ray.y) * angleTan + (*info)->player->x;
			ray.y_offset = GRID_SIZE;
			ray.x_offset = -ray.y_offset * angleTan;
		}
		if (ray.angle == 0 || ray.angle == M_PI) // looking straight left or right
		{
			ray.x = (*info)->player->x;
			ray.y = (*info)->player->x;
			depth_of_field = (*info)->m_height;
		}
		while (depth_of_field < (*info)->m_height) // increment the ray until we find a wall / are at the end of map
		{
			map.x = (int)(ray.x / GRID_SIZE);
			map.y = (int)(ray.y / GRID_SIZE);
			map.map_pos = map.y * (*info)->m_width + map.x;
			if (map.map_pos > 0 && map.map_pos < (*info)->m_width * (*info)->m_height
				&& (*info)->map[map.map_pos / (*info)->m_width][map.map_pos % (*info)->m_width].ch == '1') // did we hit a wall?
			{
				depth_of_field = (*info)->m_height;
				ray.wall_dist_h = cos(ft_dtorad(ray.angle)) * (ray.x - (*info)->player->x)
									- sin(ft_dtorad(ray.angle)) * (ray.y - (*info)->player->y);
			}
			else // did not hit a wall, let's add offset to check the next iteration
			{
				ray.x += ray.x_offset;
				ray.y += ray.y_offset;
				depth_of_field++;
			}
		}
		from.x = (*info)->player->x;
		from.y = (*info)->player->y;
		to.x = (int)ray.x;
		to.y = (int)ray.y;
		draw_line(info, &from, &to, RED);
		i++;
	}
}

void	draw_rays(t_info **info)
{
	check_horizontal(info);
}
