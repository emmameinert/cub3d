
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

void	draw_wall(t_info **info, double half_wallheight, t_ray *ray, int x)
{
	t_coord		from;
	t_coord		to;
	t_texture	*text;
	double		y_inc;
	double		text_y;
	int			text_x;

	from.y = (WIN_HEIGHT / 2) - half_wallheight;
	from.x = x;
	to.x = from.x;
	to.y = (WIN_HEIGHT / 2) + half_wallheight;
	text = get_texture(info, ray);
	text_y = 0;
	if ((half_wallheight * 2) > WIN_HEIGHT)
		text_y = ((half_wallheight * 2) - WIN_HEIGHT / 2) * x;
	if (ray->wall_color == NO || ray->wall_color == SO)
		text_x = (int)(ray->x * text->width / GRID_SIZE) % text->width;
	else if (ray->wall_color == WE || ray->wall_color == EA)
		text_x = (int)(ray->y * text->width / GRID_SIZE) % text->width;
	y_inc = text->height / (half_wallheight * 2);
	while (text_y < text->height && from.y <= to.y)
	{
		put_pixel(info, from.x, from.y, text->matrix[(int)floor(text_y)][text_x]);
		from.y++;
		text_y += y_inc;
	}
}

//void	draw_wall(t_info **info, double wallheight, t_ray *ray, int x)
//{
//	t_texture	*text;
//	int			y_pos;
//	int			x_pos;
//	double		y_step;
//	int			color;

//	y_pos = 0;
//	x_pos = 0;
//	text = get_texture(info, ray);
//	y_step = text->height / (wallheight); // do we need just the half?
//	if (wallheight > WIN_HEIGHT)
//		y_pos = ((wallheight - WIN_HEIGHT) / 2) * y_step;
//	if (ray->wall_color == NO)
//		x_pos = text->width - 1 - ((int)ray->x % text->width);
//	else if (ray->wall_color == WE)
//		x_pos = (int)ray->y % text->width;
//	else if (ray->wall_color == SO)
//		x_pos = (int)ray->x % text->width;
//	else if (ray->wall_color == EA)
//		x_pos = text->width - 1 - ((int)ray->y % text->width);
//	while (y_pos < ray->y)
//	{
//		mlx_pixel_put(info->mlx->mlx, info->mlx->window, ray->x, );
//	}
//}
