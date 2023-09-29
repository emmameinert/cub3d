
#include "../../headers/cubed.h"

static void	iterate_up(t_info **info)
{
	(*info)->ray->y = ((int)(*info)->player->y) - 0.0001;
	(*info)->ray->x = ((*info)->player->y - (*info)->ray->y)
						* (*info)->ray->tan + (*info)->player->x;
	(*info)->ray->y_offset = -GRID_SIZE;
	(*info)->ray->x_offset = -(*info)->ray->y_offset * (*info)->ray->tan;
}

static void	iterate_down(t_info **info)
{
	(*info)->ray->y = (*info)->player->y + GRID_SIZE;
	(*info)->ray->x = ((*info)->player->y - (*info)->ray->y)
						* (*info)->ray->tan + (*info)->player->x;
	(*info)->ray->y_offset = GRID_SIZE;
	(*info)->ray->x_offset = -(*info)->ray->y_offset * (*info)->ray->tan;
}

static void	init_ray(t_info **info, int ray)
{
	(*info)->ray->angle = ft_angle((*info)->player->angle + ((*info)->player->fov_angle / 2) - ray);
	if ((*info)->ray->angle == 180 || (*info)->ray->angle == 0)
		(*info)->ray->angle = (*info)->ray->angle + 1;
	(*info)->ray->tan = 1.0 / tan(ft_dtorad((*info)->ray->angle));
	(*info)->ray->sin = sin(ft_dtorad((*info)->ray->angle));
}

static void	iterate_left_right(t_info **info)
{
	(*info)->ray->x = (*info)->player->x;
	(*info)->ray->y = (*info)->player->y;
}

void	cast_horizontal(t_info **info, int ray)
{
	init_ray(info, ray);
	if ((*info)->ray->sin > 0.001) // looking up
		iterate_up(info);
	else if ((*info)->ray->sin < -0.001) // looking down
		iterate_down(info);
	else 
		iterate_left_right(info);
}
