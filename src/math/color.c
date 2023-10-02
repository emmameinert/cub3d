
#include "../../headers/cubed.h"

int	ft_rgbtocolor(t_color rgb)
{
	int color;

	color = (rgb.r * 6 / 256) * 36 + (rgb.g * 6 / 256) * 6 + (rgb.b * 6 / 256);
	return (color);
}