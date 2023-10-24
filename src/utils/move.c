/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:13 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:50:14 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

void	calc_player_angle(t_info **info)
{
	(*info)->player->dir_x = cos(ft_dtorad((*info)->player->angle));
	(*info)->player->dir_y = -sin(ft_dtorad((*info)->player->angle));
}

void	rot_player(int sign, t_info **info)
{
	(*info)->player->angle = ft_angle((*info)->player->angle + (sign * PLR_ROT_STEP));
	calc_player_angle(info);
}

static int step_collides_wall(t_info **info, int y, int x)
{
	char ch;

	if (!(*info)->map[y])
		return (1);
	ch = (*info)->map[y][x].ch;
	if (ch == '1' || ch == ' ')
		return (1);
	return (0);
}

void	move_front_back(int sign_x, int sign_y, t_info **info)
{
	double	nextX;
	double	nextY;
	int		step_size;

	step_size = 3;
	nextX = ((*info)->player->x + (sign_x * ((*info)->player->dir_x * step_size))) / GRID_SIZE;
	if (!step_collides_wall(info, (int)(*info)->player->y / GRID_SIZE, (int)nextX))
		(*info)->player->x = (*info)->player->x + (sign_x * (*info)->player->dir_x);
	nextY = ((*info)->player->y + (sign_y * ((*info)->player->dir_y *  step_size))) / GRID_SIZE;
	if (!step_collides_wall(info, (int)nextY,(int)nextX))
		(*info)->player->y = (*info)->player->y + (sign_y * (*info)->player->dir_y);
}

void	move_side(int sign_x, int sign_y, t_info **info)
{
	(*info)->player->angle += (90 * sign_x);
	calc_player_angle(info);
	move_front_back(1, 1, info);
	(*info)->player->angle += (90 * sign_y);
}
