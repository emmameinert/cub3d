/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:50:25 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:50:26 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

int	valid_char(char ch)
{
	if (ch == '1' || ch == '0' || ch == ' ')
		return (1);
	else if (ch == 'N' || ch == 'E'
		|| ch == 'W' || ch == 'S')
		return (2);
	else
		ft_put_error_exit("Invalid map character");
	return (0);
}

static void	validate_inaccessables(t_info **info)
{
	t_coord	*temp;

	(*info)->y_index = 0;
	(*info)->x_index = 0;
	while ((*info)->y_index < (*info)->m_height)
	{
		while ((*info)->x_index < (*info)->m_width)
		{
			temp = &(*info)->map[(*info)->y_index][(*info)->x_index++];
			if (!temp->checked && temp->ch == '0')
				ft_put_error_exit("Map has innaccessible area.");
		}
		(*info)->x_index = 0;
		(*info)->y_index++;
	}
}

void	validate_map_exists(t_node **map)
{
	if (!ft_lstsize(*map))
		ft_put_error_exit("Map non-existant or not last as input");
}

void	validate_map(t_node **map, t_info **info)
{
	if (!map || !*info)
		ft_put_error_exit("No map found");
	flood_fill(info, (*info)->player->y, (*info)->player->x);
	validate_inaccessables(info);
}
