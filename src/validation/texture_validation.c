
#include "../../headers/cubed.h"

char	*texture_file_existence(char *texture_file, char *msg, char *file)
{
	suffix_cmp(file, ".xpm");
	if (texture_file)
		ft_put_error_exit(msg);
	return (ft_strtrim(file, "\n"));
}

void	validate_texture_count(int counter)
{
	if (counter < 6)
		ft_put_error_exit("Error with missing textures");
}
