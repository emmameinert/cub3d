/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:02 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/07 10:49:30 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

void	exit_success(t_info **info)
{
	mlx_destroy_image((*info)->mlx->mlx, (*info)->mlx->img);
	mlx_destroy_window((*info)->mlx->mlx, (*info)->mlx->window);
	exit(0);
}

void	exit_failure(void)
{
	exit(1);
}
