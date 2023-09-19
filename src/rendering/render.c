
#include "../../headers/cubed.h"

void	create_grid(t_info **info, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 15)
	{
		j = -1;
		while (++j < 15)
			put_pixel(info, x + i, y + j, color);
	}
}

void	draw2Dmap(t_info **info)
{
	int x;
	int y;
	int	color;

	y = 0;
	x = 0;
	while (y < (*info)->m_height)
	{
		while (x < (*info)->m_width)
		{
			if ((*info)->map[y][x].ch == '1')
				color = RED;
			else if ((*info)->map[y][x].ch == '0')
				color = WHITE;
			if ((*info)->map[y][x].ch == ' ')
				color = BLACK;
			else
				color = WHITE;
			create_grid(info, y * 16, x * 16, color);
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_background(t_info **info)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			put_pixel(info, x, y, ROYAL_BLUE);
		}
	}
}

void	render(t_info **info)
{
	draw_background(info);
	draw2Dmap(info);
	mlx_put_image_to_window((*info)->mlx->mlx, (*info)->mlx->window, (*info)->mlx->img->img, 0, 0);
}
