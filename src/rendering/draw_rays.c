
#include "../../headers/cubed.h"

void	draw_rays(t_info **info)
{
	t_coord	from;
	t_coord	to;
	int		i;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		from.x = (*info)->player->x;
		from.y = (*info)->player->y;
		to.x = (*info)->rays[i].x;
		to.y = (*info)->rays[i].y;
		draw_line(info, &from, &to, COLOR_MAGENTA);
	}
}
