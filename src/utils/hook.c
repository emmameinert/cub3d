
#include "../../headers/cubed.h"

int key_hook(int keycode, t_mlx **mlx)
{
	if (keycode == ESC)
		exit_success(mlx);
	return (0);
}

int on_destroy(t_mlx **mlx)
{
	exit_success(mlx);
	return(0);
}
