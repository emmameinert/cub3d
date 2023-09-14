#include "../../headers/cubed.h"

static int	on_edge(t_info **info, int y, int x)
{
	if (y == 0 || x == 0
		|| x == ((*info)->m_width - 1)
		|| y == ((*info)->m_height - 1))
		return (1);
	return (0);
}

void	flood_fill(t_info **info, int y, int x)
{
	t_coord *temp;

	temp = &(*info)->map[y][x];
	if (temp->ch == ' ')
		ft_put_error_exit("Invalid map");
	else if (temp->checked)
		return ;
	if (temp->ch == '1')
		return ;
	if (on_edge(info, y, x))
		ft_put_error_exit("Invalid map");
	temp->checked = 1;
	flood_fill(info, temp->y - 1, temp->x);
	flood_fill(info, temp->y, temp->x - 1);
	flood_fill(info, temp->y + 1, temp->x);
	flood_fill(info, temp->y, temp->x + 1);
}
