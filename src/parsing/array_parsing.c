/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:48:40 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 13:10:36 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

static t_coord	**init_coords(t_info *info)
{
	int		i;
	t_coord	**coords;

	coords = (t_coord **)ft_calloc(info->m_height - 1, sizeof(**coords));
	i = 0;
	while (i < info->m_height)
	{
		coords[i] = (t_coord *)ft_calloc(info->m_width, sizeof(**coords));
		i++;
	}
	return (coords);
}

void	parse_array(t_info **info, t_node **map)
{
	int		i;
	int		j;
	t_node	*temp;

	i = -1;
	temp = *map;
	(*info)->map = init_coords(*info);
	while (++i < (*info)->m_height)
	{
		j = -1;
		while (++j < (*info)->m_width)
		{
			if (temp && temp->coords->ch != '\n')
			{
				(*info)->map[i][j] = (t_coord)
				{temp->coords->x, temp->coords->y, 0, temp->coords->ch, 0};
				temp = temp->next;
			}
			else
				(*info)->map[i][j] = (t_coord){j, i, 0, ' ', 0};
		}
		if (temp && temp->coords->ch == '\n')
			temp = temp->next;
	}
}
