#include "../headers/cubed.h"

t_data *set_info(void)
{
    t_data *info;

    info = ft_calloc(1, sizeof(info));
    if (!info)
    {
        ft_putstr_fd("Error with allocation\n", 2);
        exit(1);
    }
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