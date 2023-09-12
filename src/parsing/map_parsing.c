
#include "../../headers/cubed.h"

static	void	double_player_validation(t_info **info, int x)
{
	if ((*info)->begin->x == 0)
	{
		(*info)->begin->x = x - 1;
		(*info)->begin->y = (*info)->m_height;
	}
	else
		ft_put_error_exit("Too many players");
}

static void	parse_row(char *input, t_node **map, t_info **info)
{
	int			x;
	int			start;

	start = 0;
	x = 0;
	while (*input)
	{
		if (*input == '\n')
		{
			*map = ft_lstadd_back(map, x, (*info)->m_height, '\n');
			break ;
		}
		start = valid_char(*input);
		*map = ft_lstadd_back(map, x++, (*info)->m_height, *input);
		if (start == 2)
			double_player_validation(info, x);
		input++;
	}
	if (x > (*info)->m_width)
		(*info)->m_width = x;
}

static void	init_height_width(t_info **info, int first_line_parsed)
{
	if (first_line_parsed)
	{
		(*info)->m_width = first_line_parsed;
		(*info)->m_height = 1;
	}
	else
	{
		(*info)->m_width = 0;
		(*info)->m_height = 0;
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
		if ((*info)->m_height == 0 && line && line[0] == '\n')
		{
			free(line);
			continue ;
		}
		(*info)->m_height++;
		parse_row(line, map, info);
		free(line);
	}

}
static void	print_map(t_info **info)
{
	int i;
	int j;

	i = 0;
	while (i < (*info)->m_height)
	{
		j = 0;
		while (j < (*info)->m_width)
		{
			printf("[%c]", (*info)->map[i][j].ch);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	parse_map(int fd, t_info **info, char *line)
{
	int		width;
	t_node	*map;

	map = NULL;
	if (line)
	{
		width = 0;
		parse_row(line, &map, info);
		parse_nodes(fd, &map, info, width);
	}
	else
		parse_nodes(fd, &map, info, 0);
	if ((*info)->begin->x == 0)
		ft_put_error_exit("missing player");
	parse_array(info, &map);
	//printf("player start: %d %d\n", (*textures)->x_start, (*textures)->y_start);
	printf("map height: %d, map width: %d\n", (*info)->m_height, (*info)->m_width);
	print_map(info);
	// TODO clean up map
	validate_map(&map, info); // TODO: actual flood fill
}
