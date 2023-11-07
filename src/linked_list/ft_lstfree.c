/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:53:15 by meskelin          #+#    #+#             */
/*   Updated: 2023/11/07 11:05:04 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lst.h"

static void	ft_clr_rec(t_node *lst)
{
	if (!lst)
		return ;
	ft_clr_rec(lst->next);
	lst->next = NULL;
	free(lst->coords);
	free(lst);
}

void	ft_lstfree(t_node **lst)
{
	if (!lst || !*lst)
		return ;
	ft_clr_rec(*lst);
	*lst = NULL;
}
