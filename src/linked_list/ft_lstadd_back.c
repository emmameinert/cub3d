
#include "../../headers/lst.h"

void	ft_lstadd_back(t_node **lst, int x, int y, char ch)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = ft_lstnew(x, y, ch);
	else
		ft_lstlast(*lst)->next = ft_lstnew(x, y, ch);
}
