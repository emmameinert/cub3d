
#include "libft.h"

static int	ft_check_overflow(long sign)
{
	if (sign > 0)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	result = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str - '0';
		if (result < 0)
			return (ft_check_overflow(sign));
		str++;
	}
	return ((int)result * sign);
}
