/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:48:02 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:48:04 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

static t_mlx *init_mlx_wind(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ft_calloc(1, sizeof(*mlx));
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		ft_put_error_exit("Mlx could not be initialized!");
	mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!mlx->window)
		ft_put_error_exit("Mlx window could not be initialized!");
	return (mlx);
}

static t_img *init_img(t_info **info)
{
	t_img	*img;

	img = (t_img *)ft_calloc(1, sizeof(*img));
	img->img = mlx_new_image((*info)->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img->img)
		ft_put_error_exit("Mlx img could not be initialized!");
	return (img);
}

void	init_mlx(t_info **info)
{
	(*info)->mlx = init_mlx_wind();
	(*info)->mlx->img = init_img(info);
}
