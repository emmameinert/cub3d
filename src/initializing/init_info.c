/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:47:57 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 13:12:19 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

static void	init_rgb(t_color **color)
{
	(*color)->r = -2;
	(*color)->g = -2;
	(*color)->b = -2;
}

static void	init_texture(t_texture **texture, int type)
{
	(*texture)->img = ft_calloc(1, sizeof(t_img));
	(*texture)->type = type;
}

static void	init_textures(t_info **info)
{
	(*info)->no = ft_calloc(1, sizeof(t_texture));
	init_texture(&(*info)->no, NO);
	(*info)->so = ft_calloc(1, sizeof(t_texture));
	init_texture(&(*info)->so, SO);
	(*info)->ea = ft_calloc(1, sizeof(t_texture));
	init_texture(&(*info)->ea, EA);
	(*info)->we = ft_calloc(1, sizeof(t_texture));
	init_texture(&(*info)->we, WE);
}

static void	init_colors(t_info **info)
{
	(*info)->ceiling = ft_calloc(1, sizeof(t_color));
	(*info)->floor = ft_calloc(1, sizeof(t_color));
	init_rgb(&((*info)->ceiling));
	init_rgb(&((*info)->floor));
	(*info)->ceiling->draw_color = 0;
	(*info)->floor->draw_color = 0;
}

t_info	*init_info(void)
{
	t_info	*info;

	info = ft_calloc(1, sizeof(*info));
	init_player(&info);
	init_colors(&info);
	init_textures(&info);
	info->m_width = 0;
	info->m_height = 0;
	info->y_index = 0;
	info->x_index = 0;
	init_mlx(&info);
	return (info);
}
