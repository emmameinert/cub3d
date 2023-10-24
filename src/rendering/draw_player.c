/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:49:33 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:49:34 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			put_pixel(info, x, y, COLOR_MAGENTA);
	}
	from.x = (*info)->player->x;
	from.y = (*info)->player->y;
	to.x = (*info)->player->x + ((*info)->player->dir_x * 8);
	to.y = (*info)->player->y + ((*info)->player->dir_y * 8);
	draw_line(info, &from, &to, COLOR_MAGENTA);
}
