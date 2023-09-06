/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:35:59 by meskelin          #+#    #+#             */
/*   Updated: 2022/11/04 14:11:04 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*str;

	str = (char *)src;
	dest = (char *)dst;
	if (str < dest && (dest < str + len))
	{
		dest += len;
		str += len;
		while (len-- > 0)
			*--dest = *--str;
	}
	else
		ft_memcpy(dst, src, len);
	dest = NULL;
	str = NULL;
	return (dst);
}
