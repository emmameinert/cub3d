
#include "../../headers/cubed.h"

int	texture_file_existence(int fd, char *msg, char *file)
{
	if (fd != -2)
		ft_put_error_exit(msg);
	suffix_cmp(file, ".xpm");
	return (open_file(file));
}

void	validate_texture_count(int counter)
{
	if (counter < 6)
		ft_put_error_exit("Error with missing textures");
}
