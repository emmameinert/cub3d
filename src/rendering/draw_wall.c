
#include "../../headers/cubed.h"

static t_texture	*get_texture(t_info **info, t_ray *ray)
{
	if (ray->wall_color == NO)
		return ((*info)->no);
	if (ray->wall_color == SO)
		return ((*info)->so);
	if (ray->wall_color == WE)
		return ((*info)->we);
	return ((*info)->ea);
}

void	draw_wall(t_info **info, double half_wallheight, t_ray *ray)
{
	t_coord		from;
	t_coord		to;
	t_texture	*text;
	double		y_inc;
	int			text_y;
	int			text_x;

	from.y = (WIN_HEIGHT / 2) - half_wallheight;
	from.x = ray->x;
	text = get_texture(info, ray);
	text_x = (int)(ray->x * (text->width / GRID_SIZE)) % text->width;
	y_inc = (half_wallheight * 2) / text->height;
	text_y = -1;
	to.x = from.x;
	to.y = from.y + y_inc;
	while (++text_y < text->height)
	{
		draw_y_line(info, &from, &to, text->matrix[text_y][text_x]);
		from.y = to.y;
		to.y += y_inc;
	}
}
