
#include "../headers/cubed.h"

void exit_success(t_mlx **mlx)
{
	if (mlx)
		mlx_destroy_window((*mlx)->mlx, (*mlx)->window);
	exit(0);
}

void	exit_failure(void)
{
	exit(1);
}
