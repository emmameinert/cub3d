
#include "../../headers/cubed.h"

static void	iterate_right(t_info **info)
{
	(*info)->ray_v->x = ((*info)->player->x / GRID_SIZE * GRID_SIZE) + GRID_SIZE;
	(*info)->ray_v->y = ((*info)->player->x - (*info)->ray_v->x) * (*info)->ray_v->tan + (*info)->player->y;
	(*info)->ray_v->x_offset = GRID_SIZE;
	(*info)->ray_v->y_offset = -(*info)->ray_v->x_offset * (*info)->ray_v->tan;
}

static void	iterate_left(t_info **info)
{
	(*info)->ray_v->x = ((*info)->player->x / GRID_SIZE * GRID_SIZE) - 0.001;
	(*info)->ray_v->y = ((*info)->player->x - (*info)->ray_v->x) * (*info)->ray_v->tan + (*info)->player->y;
	(*info)->ray_v->x_offset = -GRID_SIZE;
	(*info)->ray_v->y_offset = -(*info)->ray_v->x_offset * (*info)->ray_v->tan;
}

static void	iterate_back_front(t_info **info)
{
	(*info)->ray_v->x = (*info)->player->x;
	(*info)->ray_v->y = (*info)->player->x;
}

static void	init_ray(t_info **info)
{
	(*info)->ray_v->wall_dist_v = 1000000;
	(*info)->ray_v->angle = ft_angle((*info)->player->angle + (*info)->player->fov_angle / 2);
	(*info)->ray_v->tan = tan(ft_dtorad((*info)->ray_v->angle));
	(*info)->ray_v->cos = cos(ft_dtorad((*info)->ray_v->angle));
}

static void	find_wall(t_info **info)
{
	int dov;

	if ((*info)->ray_v->x == (*info)->player->x
		&& (*info)->ray_v->y == (*info)->player->y)
		dov = (*info)->m_width;
	else
		dov = 0;
	while (dov < (*info)->m_height) // increment the ray until we find a wall / are at the edge of map
	{
		(*info)->ray_map->x = (int)((*info)->ray_v->x / GRID_SIZE);
		(*info)->ray_map->y = (int)((*info)->ray_v->y / GRID_SIZE);
		(*info)->ray_map->map_pos = (*info)->ray_map->y * (*info)->m_width + (*info)->ray_map->x;
		if ((*info)->ray_map->map_pos > 0 && (*info)->ray_map->map_pos < (*info)->m_width * (*info)->m_height
			&& (*info)->map[(*info)->ray_map->map_pos / (*info)->m_width][(*info)->ray_map->map_pos % (*info)->m_width].ch == '1') // did we hit a wall?
		{
			dov = (*info)->m_width;
			(*info)->ray_v->wall_dist_h = cos(ft_dtorad((*info)->ray_v->angle)) * ((*info)->ray_v->x - (*info)->player->x)
								- sin(ft_dtorad((*info)->ray_v->angle)) * ((*info)->ray_v->y - (*info)->player->y);
			return ;
		}
		(*info)->ray_v->x += (*info)->ray_v->x_offset;
		(*info)->ray_v->y += (*info)->ray_v->y_offset;
		dov++;
	}
}

void	cast_vertical(t_info **info)
{
	t_coord from;
	t_coord to;

	init_ray(info);
	if ((*info)->ray_v->cos > 0.001) // looking right
		iterate_right(info);
	else if ((*info)->ray_v->cos < -0.001) // looking left
		iterate_left(info);
	else if ((*info)->ray_v->angle == 0 || (*info)->ray_v->angle == 360) // looking straight up or down, could just be an else?
		iterate_back_front(info);
	find_wall(info);
	from.x = (*info)->player->x;
	from.y = (*info)->player->y;
	to.x = (int)(*info)->ray_v->x;
	to.y = (int)(*info)->ray_v->y;
	draw_line(info, &from, &to, RED);
}
