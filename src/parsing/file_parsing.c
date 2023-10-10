
#include "../../headers/cubed.h"

void	validate_parse_input(int fd, t_info **info)
{
	char		*line;

	line = NULL;
	line = parse_textures(fd, info);
	parse_map(fd, info, line);
	parse_player(&(*info)->player);
}
