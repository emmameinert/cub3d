/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:02 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/07 11:17:41 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

static void free_mlx(t_info **info)
{
	mlx_destroy_image((*info)->mlx->mlx, (*info)->mlx->img->img);
	free((*info)->mlx->img);
	mlx_destroy_image((*info)->mlx->mlx, (*info)->no->img->img);
	free((*info)->no->img);
	free((*info)->no);
	mlx_destroy_image((*info)->mlx->mlx, (*info)->so->img->img);
	free((*info)->so->img);
	free((*info)->so);
	mlx_destroy_image((*info)->mlx->mlx, (*info)->ea->img->img);
	free((*info)->ea->img);
	free((*info)->ea);
	mlx_destroy_image((*info)->mlx->mlx, (*info)->we->img->img);
	free((*info)->we->img);
	free((*info)->we);
	mlx_destroy_window((*info)->mlx->mlx, (*info)->mlx->window);
	free((*info)->mlx);
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
