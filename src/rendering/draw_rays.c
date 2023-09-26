
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
	dist_v = 1000000;
	dist_h = 1000000;
	while (i < 1)
	{
		cast_vertical(info);
		dist_v = find_wall(info, (*info)->m_width);
		set_line(info, (*info)->ray->x, (*info)->ray->y); // set initially based on the vertical wall hit
		cast_horizontal(info);
		dist_h = find_wall(info, (*info)->m_height);
		if (dist_h < dist_v)
			set_line(info, (*info)->ray->x, (*info)->ray->y); // horizontal wall hit is closer, use that
		draw_ray(info, (*info)->line);
		i++;
	}
}
