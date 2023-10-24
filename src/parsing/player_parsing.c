/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:48:56 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:48:57 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

void	parse_player(t_player **player)
{
	(*player)->x = (*player)->x * GRID_SIZE + PLR_SIZE;
	(*player)->y = (*player)->y * GRID_SIZE + PLR_SIZE;
	if ((*player)->dir == 'E')
		(*player)->angle = 0;
	if ((*player)->dir == 'S')
		(*player)->angle = 270;
	if ((*player)->dir == 'W')
		(*player)->angle = 180;
	if ((*player)->dir == 'N')
		(*player)->angle = 90;
	(*player)->fov = 60;
	(*player)->dir_x = cos(ft_dtorad((*player)->angle));
	(*player)->dir_y = -sin(ft_dtorad((*player)->angle));
	(*player)->ray_increment = ((*player)->fov / (double)WIN_WIDTH);
}
