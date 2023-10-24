/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:48:49 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:48:51 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

static	void	validate_number_of_players(t_info **info, int x)
{
	if ((*info)->player->x == -2)
	{
		(*info)->player->x = (double)x;
		(*info)->player->y = (double)(*info)->y_index;
	}
	else
		ft_put_error_exit("Too many players");
}

static void	parse_row(char *input, t_node **map, t_info **info)
{
	int			x;

	x = 0;
	while (*input)
	{
		if (*input == '\n')
		{
			*map = ft_lstadd_back(map, x, (*info)->y_index, '\n');
			break ;
		}
		if (valid_char(*input) == 2)
		{
			validate_number_of_players(info, x);
			(*info)->player->dir = *input;
		}
		*map = ft_lstadd_back(map, x++, (*info)->y_index, *input);
		input++;
	}
	if (x > (*info)->x_index)
		(*info)->x_index = x;
}

static void	init_height_width(t_info **info, int first_line_parsed)
{
	if (first_line_parsed)
	{
		(*info)->y_index = first_line_parsed;
		(*info)->x_index = 1;
	}
	else
	{
		(*info)->y_index = 0;
		(*info)->x_index = 0;
	}
}

static void	parse_nodes(int fd, t_node **map, t_info **info, int first_line_parsed)
{
	char	*line;

	init_height_width(info, first_line_parsed);
	while (fd > 1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!(*info)->y_index && line && line[0] == '\n')
		{
			free(line);
			continue ;
		}
		parse_row(line, map, info);
		(*info)->y_index++;
		free(line);
	}
	validate_map_exists(map);
	(*info)->m_height = (*info)->y_index;
	(*info)->m_width = (*info)->x_index;
}

void	parse_map(int fd, t_info **info, char *line)
{
	t_node	*map;

	map = NULL;
	if (line)
	{
		parse_row(line, &map, info);
		parse_nodes(fd, &map, info, 1);
	}
	else
		parse_nodes(fd, &map, info, 0);
	if ((*info)->player->x == -2)
		ft_put_error_exit("Missing player");
	parse_array(info, &map);
	validate_map(&map, info);
}
