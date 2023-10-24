/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:48:29 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:48:30 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lst.h"

int	ft_lstsize(t_node *lst)
{
	int		count;
	t_node	*ptr;

	count = 0;
	ptr = lst;
	if (!ptr)
		return (count);
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}
