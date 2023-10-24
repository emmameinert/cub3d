/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:45:38 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:45:41 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		len;
	int		i;

	if (!s || !f)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (len > i)
	{
		(*f)(i, &s[i]);
		i++;
	}
}
