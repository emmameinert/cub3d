/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:48:36 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/07 12:01:01 by meskelin         ###   ########.fr       */
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

int	ft_rgbtocolor(t_color rgb)
{
	int	color;

	color = (rgb.r * 6 / 256) * 36 + (rgb.g * 6 / 256) * 6 + (rgb.b * 6 / 256);
	return (color);
}
