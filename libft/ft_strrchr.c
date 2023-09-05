/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:19:31 by meskelin          #+#    #+#             */
/*   Updated: 2022/11/15 20:11:56 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*counter;
	unsigned char	*temp;

	temp = 0;
	counter = (unsigned char *)s;
	while (1)
	{
		if (*counter == (unsigned char)c)
		{
			temp = counter;
		}
		if (*counter == '\0')
		{
			break ;
		}
		counter++;
	}
	counter = NULL;
	return ((char *)temp);
}
