/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:49:54 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:49:55 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

void	put_pixel(t_info **info, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < WIN_WIDTH) && (y >= 0 && y < WIN_HEIGHT))
	{
		(*info)->mlx->img->addr = mlx_get_data_addr((*info)->mlx->img->img,
				&(*info)->mlx->img->bits_per_pixel, &(*info)->mlx->img->line_length,
				&(*info)->mlx->img->endian);
		dst = (*info)->mlx->img->addr + (y * (*info)->mlx->img->line_length + x * ((*info)->mlx->img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
