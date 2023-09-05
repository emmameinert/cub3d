
#include "../../headers/cubed.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*ptr;

	count = 0;
	ptr = lst;
	if (!ptr)
		return (count);
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}
