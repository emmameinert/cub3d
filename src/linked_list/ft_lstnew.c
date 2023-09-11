
#include "../../headers/cubed.h"

t_node	*ft_lstnew(int x, int y, char ch)
{
	t_node	*new;
	t_coord	*coords;

	new = (t_node *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	coords = (t_coord*)malloc(sizeof(*coords));
	coords->x = x;
	coords->y = y;
	coords->z = 0;
	coords->ch = ch;
	new->coords = coords;
	new->next = NULL;
	return (new);
}
