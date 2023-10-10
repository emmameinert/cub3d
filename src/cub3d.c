
#include "../headers/cubed.h"

void	run_program(char **argv)
{
	int fd;
	t_info *info;

	suffix_cmp(argv[1], ".cub");
	fd = open_file(argv[1]);
	info = init_info();
	validate_parse_input(fd, &info);
	close_file(fd);
	render(&info);
	hook_loop(&info);
}
