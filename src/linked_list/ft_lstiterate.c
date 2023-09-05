
#include "../../headers/cubed.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	ft_lstiter(lst->next, f);
	f(lst->content);
}
