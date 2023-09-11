
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
