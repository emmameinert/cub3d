/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:02 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/07 11:46:41 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

static void	free_matrix(t_texture **tex)
{
	int	i;

	i = -1;
	while (++i < (*tex)->height)
		free((*tex)->matrix[i]);
	free((*tex)->matrix);
}

static void	free_mlx(t_info **info)
{
	mlx_destroy_image((*info)->mlx->mlx, (*info)->mlx->img->img);
	free((*info)->mlx->img);
	free((*info)->no->filename);
	free_matrix(&(*info)->no);
	mlx_destroy_image((*info)->mlx->mlx, (*info)->no->img->img);
	free((*info)->no->img);
	free((*info)->no);
	free((*info)->so->filename);
	free_matrix(&(*info)->so);
	mlx_destroy_image((*info)->mlx->mlx, (*info)->so->img->img);
	free((*info)->so->img);
	free((*info)->so);
	free((*info)->ea->filename);
	free_matrix(&(*info)->ea);
	mlx_destroy_image((*info)->mlx->mlx, (*info)->ea->img->img);
	free((*info)->ea->img);
	free((*info)->ea);
	free((*info)->we->filename);
	free_matrix(&(*info)->we);
	mlx_destroy_image((*info)->mlx->mlx, (*info)->we->img->img);
	free((*info)->we->img);
	free((*info)->we);
	mlx_destroy_window((*info)->mlx->mlx, (*info)->mlx->window);
}

static void	free_colors(t_info **info)
{
	free((*info)->ceiling);
	free((*info)->floor);
}

void	exit_success(t_info **info)
{
	free_mlx(info);
	free_colors(info);
	free((*info)->player);
	exit(0);
}

void	exit_failure(void)
{
	exit(1);
}
