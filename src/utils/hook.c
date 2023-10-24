/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:09 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:55:23 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

int	key_hook(int keycode, t_info **info)
{
	if (keycode == ESC)
		exit_success(&(*info)->mlx);
	calc_player_angle(info);
	if (keycode == UP)
		move_front_back(1, 1, info);
	if (keycode == DOWN)
		move_front_back(-1, -1, info);
	if (keycode == LEFT)
		move_side(1, -1, info);
	if (keycode == RIGHT)
		move_side(-1, 1, info);
	if (keycode == ROT_LEFT)
		rot_player(1, info);
	if (keycode == ROT_RIGHT)
		rot_player(-1, info);
	calc_player_angle(info);
	render(info);
	return (0);
}

int	on_destroy(t_info **info)
{
	exit_success(&(*info)->mlx);
	return (0);
}
