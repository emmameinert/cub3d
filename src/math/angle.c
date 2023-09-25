
#include "../../headers/cubed.h"
#include <math.h>

double	ft_dtorad(double angle)
{
	return (angle * M_PI / 180.0);
}

double	ft_angle(double angle)
{
	if (angle < 0)
		return (angle + 360);
	else if (angle > 360)
		return (angle - 360);
	return (angle);
}
