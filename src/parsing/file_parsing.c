
#include "../../headers/cubed.h"

void	validate_parse_file(int fd)
{
	t_textures	*textures;
	t_node		*map;

	map = NULL;
	textures = parse_textures(fd);
	parse_map(fd, &map);
	close_file(fd);
}
