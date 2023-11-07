/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:43:50 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/07 13:31:32 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoui(const char *str)
{
	long	result;

	if (!*str)
		ft_put_error_exit("Invalid color input");
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
