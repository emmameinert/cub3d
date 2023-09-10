#include "../headers/cubed.h"

t_mlx *init_mlx_wind(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ft_calloc(1, sizeof(*mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (NULL);
	mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!mlx->window)
		return (NULL);
	return (mlx);
}

t_img *init_img(t_mlx **mlx)
{
	t_img	*img;

	img = (t_img *)ft_calloc(1, sizeof(*img));
	if (!img)
		return (NULL);
	img->img = mlx_new_image((*mlx)->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img->img)
		return (NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		return (NULL);
	return (img);
}

static void    init_colors(t_color **color)
{
    (*color)->r = -2;
    (*color)->g = -2;
    (*color)->b = -2;
}

t_textures *init_info(void)
{
    t_textures *info;

    info = ft_calloc(1, sizeof(*info));
    if (!info)
    {
        ft_putstr_fd("Error with allocation\n", 2);
        exit(1);
    }
    info->no = -2;
    info->so = -2;
    info->ea = -2;
    info->we = -2;
    info->ceiling = ft_calloc(1, sizeof(t_color));
    info->floor = ft_calloc(1, sizeof(t_color));
    init_colors(&(info->ceiling));
    init_colors(&(info->floor));
    return (info);
}
