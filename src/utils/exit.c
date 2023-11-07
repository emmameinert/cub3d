/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:02 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/07 17:03:24 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

static void	free_mlx(t_info **info)
{
	mlx_destroy_image((*info)->mlx->mlx, (*info)->mlx->img->img);
	mlx_destroy_image((*info)->mlx->mlx, (*info)->no->img);
	mlx_destroy_image((*info)->mlx->mlx, (*info)->so->img);
	mlx_destroy_image((*info)->mlx->mlx, (*info)->ea->img);
	mlx_destroy_image((*info)->mlx->mlx, (*info)->we->img);
	mlx_destroy_window((*info)->mlx->mlx, (*info)->mlx->window);
}

void	exit_success(t_info **info)
{
	free_mlx(info);
	exit(0);
}

void	exit_failure(void)
{
	exit(1);
}
