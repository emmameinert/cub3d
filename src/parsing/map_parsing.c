
#include "../../headers/cubed.h"

static void	parse_row(char *input, t_node **map, int y)
{
	int			x;

	x = 0;
	while (*input)
	{
		if (*input == '\n')
			break ;
		if (valid_char(*input))
			ft_lstadd_back(map, x++, y, *input);
		else
			ft_put_error_exit("Invalid map character");
		input++;
	}
}

void	parse_map(int fd, t_node **map)
{
	int		y;
	char	*line;

	while (fd > 1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (y == 0 && line && line[0] == '\n')
		{
			free(line);
			continue ;
		}
		parse_row(line, map, y++);
		free(line);
	}
	validate_map(map);
}
