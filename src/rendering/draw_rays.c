
#include "../../headers/cubed.h"

static void	draw_ray(t_info **info)
{
	t_coord from;
	t_coord to;

	from.x = (*info)->player->x;
	from.y = (*info)->player->y;
	to.x = (int)(*info)->ray->x;
	to.y = (int)(*info)->ray->y;
	draw_line(info, &from, &to, RED);
}

void	draw_rays(t_info **info)
{
	t_ray	ray;
	t_map	ray_map;
	int		i;

	(*info)->ray = &ray;
	(*info)->ray_map = &ray_map;
	i = 0;
	while (i < 1)
	{
		cast_vertical(info);
		draw_ray(info);
		//cast_horizontal(info);
		i++;
	}
}
