
#include "../../headers/lst.h"

void	ft_lstiter(t_node *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	ft_lstiter(lst->next, f);
	f(lst->coords);
}
