
#include "../../headers/cubed.h"

void	validate_parse_file(int fd)
{
	t_textures	*info;
	char		*line;

	line = NULL;
	info = init_info();
	line = parse_textures(fd, &info);
	parse_map(fd, &info, line);
	close_file(fd);
}
