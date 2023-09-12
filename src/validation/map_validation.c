
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
void	validate_map(t_node **map, t_info **info)
{
	if (!map)
		ft_put_error_exit("No map found");
	flood_fill(info);
	printf("\n\n");
	print_map(info);
}
