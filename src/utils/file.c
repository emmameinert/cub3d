
#include "../../headers/cubed.h"

int	open_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	// if (fd == -1)
	// 	ft_put_error_exit("Failed to open the file");
	return (fd);
}

void	close_file(int fd)
{
	if (close(fd) == -1)
		ft_put_error_exit("Failed to close the file");
}

void	suffix_cmp(char *file, char *suffix)
{
	int	len;
	char	*file_ending;

	len = ft_strlen(file);
	if (!ft_strncmp_all(suffix, ".xpm"))
		file_ending = ft_substr(file, len - 5, 4);
	else
		file_ending = ft_substr(file, len - 4, 4);
	if (ft_strncmp_all(file_ending, suffix))
	{
		free(file_ending);
		ft_put_error_exit("Wrong file suffix");
	}
	free(file_ending);
}
