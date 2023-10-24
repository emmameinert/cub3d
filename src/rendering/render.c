/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:49:57 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:49:58 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

void	render(t_info **info)
{
	mlx_clear_window((*info)->mlx->mlx, (*info)->mlx->window);
	draw_background(info, WIN_HEIGHT, WIN_WIDTH);
	cast_rays(info);
	draw_maze(info);
	draw_minimap(info);
	draw_player(info);
	draw_rays(info);
	mlx_put_image_to_window((*info)->mlx->mlx, (*info)->mlx->window, (*info)->mlx->img->img, 0, 0);
}
