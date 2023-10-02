
#include "../../headers/cubed.h"

void	render(t_info **info)
{
	mlx_clear_window((*info)->mlx->mlx, (*info)->mlx->window);
	draw_background(info, WIN_HEIGHT, WIN_WIDTH);
	draw_player(info);
	draw_minimap(info);
	cast_rays(info);
	mlx_put_image_to_window((*info)->mlx->mlx, (*info)->mlx->window, (*info)->mlx->img->img, 0, 0);
}
