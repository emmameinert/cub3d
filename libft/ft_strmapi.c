/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:40:48 by meskelin          #+#    #+#             */
/*   Updated: 2022/11/11 10:19:00 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		len;
	int		i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(*ptr) * len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (len > i)
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
