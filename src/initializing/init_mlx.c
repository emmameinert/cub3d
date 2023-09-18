
#include "../../headers/cubed.h"

t_mlx *init_mlx_wind(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ft_calloc(1, sizeof(*mlx));
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		ft_put_error_exit("Mlx could not be initialized!");
	mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!mlx->window)
		ft_put_error_exit("Mlx window could not be initialized!");
	return (mlx);
}

t_img *init_img(t_mlx **mlx)
{
	t_img	*img;

	img = (t_img *)ft_calloc(1, sizeof(*img));
	img->img = mlx_new_image((*mlx)->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img->img)
		ft_put_error_exit("Mlx img could not be initialized!");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		ft_put_error_exit("Mlx img address could not be initialized!");
	return (img);
}
