
#include "../../headers/cubed.h"

t_list	*ft_lstnew(t_coord *coords)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->coords = coords;
	new->next = NULL;
	return (new);
}
