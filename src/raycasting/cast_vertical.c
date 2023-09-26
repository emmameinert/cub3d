
#include "../../headers/cubed.h"

static void	iterate_right(t_info **info)
{
	(*info)->ray->x = ((*info)->player->x / GRID_SIZE * GRID_SIZE) + GRID_SIZE;
	(*info)->ray->y = ((*info)->player->x - (*info)->ray->x) * (*info)->ray->tan + (*info)->player->y;
	(*info)->ray->x_offset = GRID_SIZE;
	(*info)->ray->y_offset = -(*info)->ray->x_offset * (*info)->ray->tan;
}

static void	iterate_left(t_info **info)
{
	(*info)->ray->x = ((*info)->player->x / GRID_SIZE * GRID_SIZE) - 0.001;
	(*info)->ray->y = ((*info)->player->x - (*info)->ray->x) * (*info)->ray->tan + (*info)->player->y;
	(*info)->ray->x_offset = -GRID_SIZE;
	(*info)->ray->y_offset = -(*info)->ray->x_offset * (*info)->ray->tan;
}

static void	iterate_back_front(t_info **info)
{
	(*info)->ray->x = (*info)->player->x;
	(*info)->ray->y = (*info)->player->x;
}

static void	init_ray(t_info **info)
{
	(*info)->ray->angle = ft_angle((*info)->player->angle + (*info)->player->fov_angle / 2);
	(*info)->ray->tan = tan(ft_dtorad((*info)->ray->angle));
	(*info)->ray->cos = cos(ft_dtorad((*info)->ray->angle));
}

void	cast_vertical(t_info **info)
{
	init_ray(info);
	if ((*info)->ray->cos > 0.001) // looking right
		iterate_right(info);
	else if ((*info)->ray->cos < -0.001) // looking left
		iterate_left(info);
	else if ((*info)->ray->angle == 0 || (*info)->ray->angle == 360) // looking straight up or down, could just be an else?
		iterate_back_front(info);
}
