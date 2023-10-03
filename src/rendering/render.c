
#include "../../headers/cubed.h"

void	render(t_info **info)
{
	mlx_clear_window((*info)->mlx->mlx, (*info)->mlx->window);
	draw_background(info, WIN_HEIGHT, WIN_WIDTH);
	cast_rays(info);
	draw_maze(info);
	draw_minimap(info);
	draw_player(info);
	// Add texture file protection to check that texture files are accessable
	draw_rays(info);
	mlx_put_image_to_window((*info)->mlx->mlx, (*info)->mlx->window, (*info)->mlx->img->img, 0, 0);
}
