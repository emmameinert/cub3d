
#include "../../headers/cubed.h"

void	draw_player(t_info **info)
{
	int	x;
	int	y;
	t_coord from;
	t_coord to;

	y = (*info)->player->y - PLR_SIZE / 2 - 1;
	while (++y < ((*info)->player->y + PLR_SIZE / 2))
	{
		x = (*info)->player->x - PLR_SIZE / 2 - 1;
		while (++x < ((*info)->player->x + PLR_SIZE / 2))
			put_pixel(info, x, y, GREEN);
	}
	from.x = (*info)->player->x;
	from.y = (*info)->player->y;
	to.x = (*info)->player->x + ((*info)->player->dir_x * 10);
	to.y = (*info)->player->y + ((*info)->player->dir_y * 10);
	draw_line(info, &from, &to, GREEN);
}
