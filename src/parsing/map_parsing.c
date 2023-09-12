
#include "../../headers/cubed.h"

static	void	double_player_validation(t_textures **texture, int x)
{
	if ((*texture)->x_start == 0)
	{
		(*texture)->x_start = x - 1;
		(*texture)->y_start = (*texture)->m_height;
	}
	else
		ft_put_error_exit("Too many players");
}

static void	parse_row(char *input, t_node **map, t_textures **texture)
{
	int			x;
	int			start;

	start = 0;
	x = 0;
	while (*input)
	{
		if (*input == '\n')
		{
			*map = ft_lstadd_back(map, x, (*texture)->m_height, '\n');
			break ;
		}
		start = valid_char(*input);
		*map = ft_lstadd_back(map, x++, (*texture)->m_height, *input);
		if (start == 2)
			double_player_validation(texture, x);
		input++;
	}
	if (x > (*texture)->m_width)
		(*texture)->m_width = x;
}

static void	init_height_width(t_textures **texture, int first_line_parsed)
{
	if (first_line_parsed)
	{
		(*texture)->m_width = first_line_parsed;
		(*texture)->m_height = 1;
	}
	else
	{
		(*texture)->m_width = 0;
		(*texture)->m_height = 0;
	}
}

static void	parse_nodes(int fd, t_node **map, t_textures **textures, int first_line_parsed)
{
	char	*line;

	init_height_width(textures, first_line_parsed);
	while (fd > 1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if ((*textures)->m_height == 0 && line && line[0] == '\n')
		{
			free(line);
			continue ;
		}
		(*textures)->m_height++;
		parse_row(line, map, textures);
		free(line);
	}

}
static void	print_map(t_textures **texture)
{
	int i;
	int j;

	i = 0;
	while (i < (*texture)->m_height)
	{
		j = 0;
		while (j < (*texture)->m_width)
		{
			printf("[%c]", (*texture)->map[i][j].ch);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	parse_map(int fd, t_textures **textures, char *line)
{
	int		width;
	t_node	*map;

	map = NULL;
	if (line)
	{
		width = 0;
		parse_row(line, &map, textures);
		parse_nodes(fd, &map, textures, width);
	}
	else
		parse_nodes(fd, &map, textures, 0);
	if ((*textures)->x_start == 0)
		ft_put_error_exit("missing player");
	parse_array(textures, &map);
	printf("player start: %d %d\n", (*textures)->x_start, (*textures)->y_start);
	printf("map height: %d, map width: %d\n", (*textures)->m_height, (*textures)->m_width);
	print_map(textures);
	// TODO clean up map
	validate_map(&map); // TODO: actual flood fill
}
