/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:46:11 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:46:13 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (len > 0 && haystack[i] != '\0')
	{
		while (needle[j] == haystack[i + j] && len > 0)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
			len--;
		}
		len += j;
		j = 0;
		i++;
		len--;
	}
	return (NULL);
}
