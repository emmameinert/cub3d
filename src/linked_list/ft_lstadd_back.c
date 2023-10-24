/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:48:11 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:48:12 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lst.h"

t_node	*ft_lstadd_back(t_node **lst, int x, int y, char ch)
{
	t_node	*new;

	new = ft_lstnew(x, y, ch);
	if (!*lst)
		lst = &new;
	else
		ft_lstlast(lst)->next = new;
	return (*lst);
}
