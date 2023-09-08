
#include "../../headers/lst.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
