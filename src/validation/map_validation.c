
#include "../../headers/cubed.h"

int	valid_char(char ch)
{
	if (ch == '1' || ch == '0' || ch == ' ')
		return (1);
	else if (ch == 'N' || ch == 'E'
		|| ch == 'W' || ch == 'S')
		return (2);
	else
		ft_put_error_exit("Invalid map character");
	return (0);
}

static void	print_map(t_info **info)
{
	int i;
	int j;

	i = 0;
	while (i < (*info)->m_height)
	{
		j = 0;
		while (j < (*info)->m_width)
		{
			printf("[%c]", (*info)->map[i][j].ch);
			j++;
		}
		printf("\n");
		i++;
	}
}

static void	validate_inaccessables(t_info **info)
{
	t_coord	*temp;

	(*info)->y_index = 0;
	(*info)->x_index = 0;
	while ((*info)->y_index < (*info)->m_height)
	{
		while ((*info)->x_index < (*info)->m_width)
		{
			temp = &(*info)->map[(*info)->y_index][(*info)->x_index++];
			if (!temp->checked && temp->ch == '0')
				ft_put_error_exit("Invalid map");
		}
		(*info)->x_index = 0;
		(*info)->y_index++;
	}
}

void	validate_map(t_node **map, t_info **info)
{
	if (!map || !*info)
		ft_put_error_exit("No map found");
	flood_fill(info, (*info)->player->y, (*info)->player->x);
	validate_inaccessables(info);
}
