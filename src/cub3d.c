
#include "../headers/cubed.h"

void run_program(char **argv)
{
    int fd;
    t_info *info;
    t_mlx *mlx;
    int height;
    int width;

    mlx = NULL;
	width = 0;
	height = 0;
    // suffix_cmp(argv[1], ".cub");
    // fd = open_file(argv[1]);
    // info = init_info();
    // validate_parse_file(fd, &info);
    mlx = init_mlx_wind();
    mlx->img = init_img(&mlx);
    mlx->img->img = mlx_xpm_file_to_image(mlx->mlx, "./textures/wolfenstein/blue_stone.xpm", &width, &height);
	printf("width: %i\n", width);
	printf("height: %i\n", height);
    mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->img, 500, 500);
    mlx_hook(mlx->window, ON_KEYDOWN, 1, key_hook, &mlx);
	mlx_hook(mlx->window, ON_DESTROY, 1, on_destroy, &mlx);
    mlx_loop(mlx->mlx);
}
