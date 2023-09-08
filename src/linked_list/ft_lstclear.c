
#include "../../headers/lst.h"

static void	ft_clr_rec(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	ft_clr_rec(lst->next, del);
	lst->next = NULL;
	del(lst->coords);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !*lst || !del)
		return ;
	ft_clr_rec(*lst, del);
	*lst = NULL;
}
