/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:48:36 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/07 13:39:05 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

void	ft_parse_color(t_color *color, int *colour)
{
	color->r = colour[0];
	color->g = colour[1];
	color->b = colour[2];
	color->draw_color = ft_rgbtocolor(*color);
}

long	ft_rgbtocolor(t_color rgb)
{
	long	color;

	color = ((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) + (rgb.b & 0xff);
	return (color);
}
