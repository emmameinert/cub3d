
#include "../../headers/cubed.h"

t_node	*ft_lstnew(t_coord *coords)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->coords = coords;
	new->next = NULL;
	return (new);
}
