
#include "../../headers/lst.h"

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*ptr;

	ptr = lst;
	if (!ptr)
		return (NULL);
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}
