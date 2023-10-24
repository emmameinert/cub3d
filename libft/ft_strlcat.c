/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:45:46 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:45:48 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	offset;
	int		src_index;

	s_len = ft_strlen(src);
	if (dstsize == 0)
		return (s_len);
	d_len = ft_strlen(dst);
	offset = d_len;
	src_index = 0;
	if (d_len < dstsize - 1 && dstsize > 0)
	{
		while (src[src_index] && d_len + src_index < dstsize - 1)
		{
			dst[offset] = src[src_index];
			offset++;
			src_index++;
		}
		dst[offset] = '\0';
	}
	if (d_len >= dstsize)
		d_len = dstsize;
	return (d_len + s_len);
}
