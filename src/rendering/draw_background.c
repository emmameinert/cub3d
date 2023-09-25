
#include "../../headers/cubed.h"

void	draw_background(t_info **info, int height, int width)
{
	int	x;
	int	y;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			put_pixel(info, x, y, ROYAL_BLUE);
	}
}
