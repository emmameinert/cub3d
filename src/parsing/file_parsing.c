
#include "../../headers/cubed.h"

void	validate_parse_file(int fd, t_info **info)
{
	char		*line;

	line = NULL;
	line = parse_textures(fd, info);
	parse_map(fd, info, line);
	close_file(fd);
}
