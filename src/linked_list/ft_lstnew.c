/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:48:26 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:48:27 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cubed.h"

t_node	*ft_lstnew(int x, int y, char ch)
{
	t_node	*new;

	new = (t_node *)ft_calloc(1, sizeof(*new));
	new->coords = (t_coord *)ft_calloc(1, sizeof(t_coord));
	new->coords->x = x;
	new->coords->y = y;
	new->coords->z = 0;
	new->coords->ch = ch;
	new->next = NULL;
	return (new);
}
