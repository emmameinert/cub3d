/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:02 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/07 11:51:43 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

static void	free_tex(t_info **info, t_texture **tex)
{
	int	i;

	if (!*tex)
		return ;
	if ((*tex)->filename)
		free((*tex)->filename);
	if ((*tex)->matrix)
	{
		i = -1;
		while (++i < (*tex)->height)
			free((*tex)->matrix[i]);
		free((*tex)->matrix);
	}
	if ((*tex)->img)
	{
		mlx_destroy_image((*info)->mlx->mlx, (*tex)->img->img);
		free((*tex)->img);
	}
	free(*tex);
}

static void	free_mlx(t_info **info)
{
	mlx_destroy_image((*info)->mlx->mlx, (*info)->mlx->img->img);
	free((*info)->mlx->img);
	free_tex(info, &(*info)->no);
	free_tex(info, &(*info)->so);
	free_tex(info, &(*info)->ea);
	free_tex(info, &(*info)->we);
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
