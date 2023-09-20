

#include "../../headers/cubed.h"

static void	create_grid(t_info **info, int x, int y, int color)
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

void	draw_minimap(t_info **info)
{
	int x;
	int y;
	int	color;
	t_coord *temp;

	y = -1;
	while (++y < (*info)->m_height)
	{
		x = -1;
		while (++x < (*info)->m_width)
		{
			temp = &(*info)->map[y][x];
			if (temp->ch == '1')
				color = RED;
			else if (temp->ch == '0')
				color = WHITE;
			else if (temp->ch == ' ')
				color = ROYAL_BLUE;
			else
				color = WHITE;
			create_grid(info, x * 16, y * 16, color);
		}
	}
}

void	draw_loop(t_info **info, int height, int width, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			put_pixel(info, x, y, color);
	}
}
