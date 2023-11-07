/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:02 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/07 10:37:19 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

static void	free_texture(t_info **info, t_texture *text)
{
	mlx_destroy_image((*info)->mlx->mlx, text->img->img);
	free(text->img->addr);
	free(text);
}

void	exit_success(t_info **info)
{
	mlx_destroy_image((*info)->mlx->mlx, (*info)->mlx->img);
	mlx_destroy_window((*info)->mlx->mlx, (*info)->mlx->window);
	free((*info)->mlx);
	free_texture(info, (*info)->no);
	free_texture(info, (*info)->so);
	free_texture(info, (*info)->we);
	free_texture(info, (*info)->ea);
	while (1)
		;
	exit(0);
}

void	exit_failure(void)
{
	exit(1);
}
