
#include "../../headers/cubed.h"

static t_coord	**init_coords(t_textures *textures)
{
	int		i;
	t_coord	**coords;

	coords = (t_coord **)ft_calloc(textures->m_height - 1, sizeof(**coords));
	i = 0;
	while (i < textures->m_height)
	{
		coords[i] = (t_coord *)ft_calloc(textures->m_widht, sizeof(**coords));
		i++;
	}
	return (coords);
}

void	parse_array(t_textures **texture, t_node **map)
{
	int		i;
	int		j;
	t_node	*temp;

	i = 0;
	j = 0;
	temp = *map;
	(*texture)->map = init_coords(*texture);
	while (i < (*texture)->m_height)
	{
		while (j < (*texture)->m_widht)
		{
			if (temp && temp->coords->ch != '\n')
			{
				(*texture)->map[i][j++] = (t_coord){ temp->coords->x, temp->coords->y, 0, temp->coords->ch };
				temp = temp->next;
			}
			else
			{
				(*texture)->map[i][j] = (t_coord){ j, i, 0, ' ' };
				j++;
			}
		}
		if (temp && temp->coords->ch == '\n')
			temp = temp->next;
		j = 0;
		i++;
	}
}
