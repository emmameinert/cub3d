/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:12:25 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 13:19:53 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

void	init_player(t_info **info)
{
	(*info)->player = ft_calloc(1, sizeof(t_player));
	(*info)->player->x = -2;
	(*info)->player->y = -2;
	(*info)->player->angle = 60;
	(*info)->player->dir_x = 0;
	(*info)->player->dir_y = 0;
	(*info)->player->move_speed = 0.5;
	(*info)->player->rot_speed = 5.0;
}
