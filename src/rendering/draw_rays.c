
#include "../../headers/cubed.h"

void	draw_rays(t_info **info, t_ray *ray)
{
	t_coord from;
	t_coord to;

	from.x = (*info)->player->x;
	from.y = (*info)->player->y;
	to.x = ray->x;
	to.y = ray->y;
	draw_line(info, &from, &to, BLACK);
}