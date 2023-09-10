#include "libft.h"

int	ft_atoui(const char *str)
{
	long	result;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
		return (-1);
	else if (*str == '+')
		str++;
	result = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str - '0';
		if (result < -2147483648 || result > 2147483647)
			return (-1);
		str++;
	}
	return ((int)result);
}