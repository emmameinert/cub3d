/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:48:14 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 11:48:15 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lst.h"

static void	ft_clr_rec(t_node *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	ft_clr_rec(lst->next, del);
	lst->next = NULL;
	del(lst->coords);
	free(lst);
}

void	ft_lstclear(t_node **lst, void (*del)(void *))
{
	if (!lst || !*lst || !del)
		return ;
	ft_clr_rec(*lst, del);
	*lst = NULL;
}
