/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:49:47 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:49:48 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	double		to_y;
	t_texture	*text;
	double		y_inc;
	double		text_y;

	from.x = x;
	from.y = (WIN_HEIGHT / 2) - half_wallheight;
	to_y = (WIN_HEIGHT / 2) + half_wallheight;
	text = get_texture(info, ray);
	text_y = 0;
	y_inc = text->height / (half_wallheight * 2);
	while (text_y < text->height && from.y <= to_y)
	{
		put_pixel(info, from.x, from.y, text->matrix[(int)floor(text_y)][ray->text_x]);
		from.y++;
		text_y += y_inc;
	}
}
