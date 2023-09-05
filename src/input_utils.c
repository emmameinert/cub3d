#include "../headers/cubed.h"

t_data *set_info(void)
{
    t_data *info;

    info = ft_calloc(1, sizeof(info));
    return (info);
}

int     open_file(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	return (fd);
}