#include "../headers/cubed.h"

int key_hook(t_mlx **mlx, int keycode)
{
    if (keycode == 53)
        exit_success(mlx);
    return (0);
}

int finish_destroy(t_mlx **mlx)
{
    exit_success(mlx);
    return(0);
}