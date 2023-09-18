
#include "../../headers/cubed.h"

static t_coord	**init_coords(t_info *info)
{
	int		i;
	t_coord	**coords;

	coords = (t_coord **)ft_calloc(info->m_height - 1, sizeof(**coords));
	i = 0;
	while (i < info->m_height)
	{
		coords[i] = (t_coord *)ft_calloc(info->m_width, sizeof(**coords));
		i++;
	}
	return (coords);
}

void	parse_array(t_info **info, t_node **map)
{
	int		i;
	int		j;
	t_node	*temp;

	i = 0;
	j = 0;
	temp = *map;
	(*info)->map = init_coords(*info);
	while (i < (*info)->m_height)
	{
		while (j < (*info)->m_width)
		{
			if (temp && temp->coords->ch != '\n')
			{
				(*info)->map[i][j++] = (t_coord){ temp->coords->x, temp->coords->y, 0, temp->coords->ch, 0 };
				temp = temp->next;
			}
			else
			{
				(*info)->map[i][j] = (t_coord){ j, i, 0, ' ', 0 };
				j++;
			}
		}
		if (temp && temp->coords->ch == '\n')
			temp = temp->next;
		j = 0;
		i++;
	}
}
