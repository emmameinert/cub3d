
#include "../../headers/cubed.h"

static void	parse_row(char *input, t_node **map, int y, int *longest_x)
{
	int			x;

	x = 0;
	while (*input)
	{
		if (*input == '\n')
		{
			*map = ft_lstadd_back(map, x, y, '\n');
			break ;
		}
		if (valid_char(*input))
			*map = ft_lstadd_back(map, x++, y, *input);
		else
			ft_put_error_exit("Invalid map character");
		input++;
	}
	if (x > *longest_x)
		*longest_x = x;
}

static void	init_height_width(int *height, int *width, int first_line_parsed)
{
	if (first_line_parsed)
	{
		(*width) = first_line_parsed;
		(*height) = 1;
	}
	else
	{
		(*width) = 0;
		(*height) = 0;
	}
}

static void	parse_nodes(int fd, t_node **map, t_textures **textures, int first_line_parsed)
{
	char	*line;
	int		height;
	int		width;

	init_height_width(&height, &width, first_line_parsed);
	while (fd > 1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (height == 0 && line && line[0] == '\n')
		{
			free(line);
			continue ;
		}
		parse_row(line, map, height++, &width);
		free(line);
	}
	(*textures)->m_height = height;
	(*textures)->m_widht = width;
}

void	parse_map(int fd, t_textures **textures, char *line)
{
	int		widht;
	t_node	*map;

	map = NULL;
	if (line)
	{
		widht = 0;
		parse_row(line, &map, 0, &widht);
		parse_nodes(fd, &map, textures, widht);
	}
	else
		parse_nodes(fd, &map, textures, 0);
	parse_array(textures, &map);
	// TODO clean up map
	validate_map(&map); // TODO: actual flood fill
}
