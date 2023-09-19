
#include "../../headers/cubed.h"

void	render(t_info **info)
{
	draw_background(info);
	draw_minimap(info);
	mlx_put_image_to_window((*info)->mlx->mlx, (*info)->mlx->window, (*info)->mlx->img->img, 0, 0);
}
