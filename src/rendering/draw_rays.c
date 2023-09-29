
#include "../../headers/cubed.h"

static void	draw_ray(t_info **info, t_coord *to)
{
	t_coord from;

	from.x = (*info)->player->x;
	from.y = (*info)->player->y;
	draw_line(info, &from, to, RED);
}

static void	set_line(t_info **info, double x, double y)
{
	(*info)->line->x = x;
	(*info)->line->y = y;
}

void	draw_rays(t_info **info)
{
	double	dist_v;
	double	dist_h;
	int		i;

	i = 0;
	while (i < 60)
	{
		dist_v = 100000;
		cast_vertical(info, i);
		dist_v = find_wall(info, (*info)->m_width);
		set_line(info, (*info)->ray->x, (*info)->ray->y); // set initially based on the vertical wall hit
		dist_h = 100000;
		cast_horizontal(info, i);
		dist_h = find_wall(info, (*info)->m_height);
		// printf("hori: %f verti:%f\n", dist_h, dist_v);
		if (dist_h < dist_v)
			set_line(info, (*info)->ray->x, (*info)->ray->y);	 // horizontal wall hit is closer, use that
		dist_h = dist_v;
		draw_ray(info, (*info)->line);
		// printf("ray angle: %f player angle: %f i: %d\n", (*info)->ray->angle, (*info)->player->angle, i);
		i += 29;
	}
}
