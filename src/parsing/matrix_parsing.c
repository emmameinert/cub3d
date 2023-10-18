
#include "../../headers/cubed.h"

static void	parse_matrix(t_texture **tex)
{
	int	i;
	int	j;

	(*tex)->matrix = ft_calloc((*tex)->height, sizeof(int *));
	i = -1;
	while (++i < (*tex)->height)
		(*tex)->matrix[i] = ft_calloc((*tex)->width, sizeof(int));
	i = -1;
	j = -1;
	while (++i < (*tex)->height)
	{
		j = -1;
		while (++j < (*tex)->width)
		{
			(*tex)->matrix[i][j] = *(unsigned int *)((*tex)->img->addr
								+ ((*tex)->img->line_length * i)
								+ (j * ((*tex)->img->bits_per_pixel / 8)));
		}
	}
}

static void	parse_texture_matrix(t_info **info, t_texture **tex)
{
	(*tex)->img->img = mlx_xpm_file_to_image((*info)->mlx->mlx, (*tex)->filename, &(*tex)->width, &(*tex)->height);
	if (!(*tex)->img->img)
		ft_put_error_exit("Can't open texture file");
	(*tex)->img->addr = mlx_get_data_addr((*tex)->img->img, &(*tex)->img->bits_per_pixel,
						&(*tex)->img->line_length, &(*tex)->img->endian);
	if (!(*tex)->img->addr)
		ft_put_error_exit("Can't read texture data");
	parse_matrix(tex);
}

void	parse_matrices(t_info **info)
{
	parse_texture_matrix(info, &(*info)->no);
	parse_texture_matrix(info, &(*info)->so);
	parse_texture_matrix(info, &(*info)->ea);
	parse_texture_matrix(info, &(*info)->we);
}
