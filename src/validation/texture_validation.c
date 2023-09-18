
#include "../../headers/cubed.h"

char	*texture_file_existence(char *msg, char *file)
{
	suffix_cmp(file, ".xpm");

	return (ft_strtrim(file, "\n"));
}

void	validate_texture_count(int counter)
{
	if (counter < 6)
		ft_put_error_exit("Error with missing textures");
}
