
#include "../../headers/cubed.h"

void	render(t_info **info)
{
	draw_loop(info, WIN_HEIGHT, WIN_WIDTH, ROYAL_BLUE);
	draw_minimap(info);
	draw_loop(info, 5, 5, GREEN);
	mlx_put_image_to_window((*info)->mlx->mlx, (*info)->mlx->window, (*info)->mlx->img->img, 0, 0);
}
