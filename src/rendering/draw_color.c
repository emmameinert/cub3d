/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:49:15 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:49:17 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
