/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:49:50 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:49:51 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

void	hook_loop(t_info **info)
{
	mlx_hook((*info)->mlx->window, ON_KEYDOWN, 1, key_hook, info);
	mlx_hook((*info)->mlx->window, ON_DESTROY, 1, on_destroy, info);
	mlx_loop((*info)->mlx->mlx);
}
