
#include "libft.h"

int	ft_abs(int value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}

int	ft_dabs(double value)
{
	if (value < 0)
		return ((int)value * -1);
	return ((int)value);
}
