/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:46:22 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:46:23 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_empty_str(char *str)
{
	str = (char *)malloc(sizeof(*str));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;
	size_t	actual_len;

	str = NULL;
	if (!s)
		return (NULL);
	actual_len = ft_strlen(s);
	if (start >= actual_len)
		return (ft_empty_str(str));
	if (actual_len < len)
		len = actual_len;
	str = (char *)malloc(sizeof(*str) * len + 1);
	if (!str)
		ft_put_error_exit("Memory allocation issue");
	index = 0;
	while (len > index && s[start + index])
	{
		str[index] = s[start + index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
