#include "../headers/cubed.h"

t_data *set_info(void)
{
    t_data *info;

    info = ft_calloc(1, sizeof(info));
    //check mising
    return (info);
}

int     open_file(char *file)
{
    int fd;
    //check access here
    fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	return (fd);
}