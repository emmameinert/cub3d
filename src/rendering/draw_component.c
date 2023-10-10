
#include "../../headers/cubed.h"

void	draw_ceiling(t_info **info, double half_wallheight, int x)
{
	t_coord	from;
	t_coord	to;

	from.y = 0;
	to.y = (WIN_HEIGHT / 2) - half_wallheight;
	from.x = x;
	to.x = x;
	draw_y_line(info, &from, &to, (*info)->ceiling->draw_color);
}

void	draw_wall(t_info **info, double half_wallheight, int x)
{
	t_coord	from;
	t_coord	to;

	from.y = (WIN_HEIGHT / 2) - half_wallheight;
	to.y = (WIN_HEIGHT / 2) + half_wallheight;
	from.x = x;
	to.x = x;
	draw_y_line(info, &from, &to, (*info)->rays[x].wall_color);
}

void	draw_floor(t_info **info, double half_wallheight, int x)
{
	t_coord	from;
	t_coord	to;

	from.y = (WIN_HEIGHT / 2) + half_wallheight;
	to.y = WIN_HEIGHT;
	from.x = x;
	to.x = x;
	draw_y_line(info, &from, &to, (*info)->floor->draw_color);
}

void	draw_screen(t_info **info, int x)
{
	t_coord	from;
	t_coord	to;

	from.y = 0;
	to.y = WIN_HEIGHT;
	from.x = x;
	to.x = x;
	draw_y_line(info, &from, &to, COLOR_GRAY);
}
