
#include "../headers/cubed.h"

void run_program(char **argv)
{
	int fd;
	t_info *info;

	suffix_cmp(argv[1], ".cub");
	fd = open_file(argv[1]);
	info = init_info();
	validate_parse_input(fd, &info);
	info->no->img->img = mlx_xpm_file_to_image(info->mlx->mlx, info->no->filename, &info->no->width, &info->no->height);
	mlx_put_image_to_window(info->mlx->mlx, info->mlx->window, info->no->img->img, 500, 500);
	hook_loop(&info);
}
