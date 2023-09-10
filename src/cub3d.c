#include "../headers/cubed.h"

void run_program(char **argv)
{
    int fd;
    t_mlx *mlx;

    mlx = NULL;
    suffix_cmp(argv[1], ".cub");
    fd = open_file(argv[1]);
    validate_parse_file(fd);
    mlx = init_mlx_wind();
    mlx->img = init_img(&mlx);
    mlx_hook(mlx->window, ON_KEYDOWN, 1, key_hook, &mlx);
	mlx_hook(mlx->window, ON_DESTROY, 1, on_destroy, &mlx);
    mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->img, 0, 0);
    mlx_loop(mlx->mlx);
    close(fd);
}
