/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:43:40 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:43:42 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
