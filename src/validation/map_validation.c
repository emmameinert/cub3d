
#include "../../headers/cubed.h"

int	valid_char(char ch)
{
	if (ch == '1' || ch == '0' || ch == ' ')
		return (1);
	else if (ch == 'N' || ch == 'E'
		|| ch == 'W' || ch == 'S')
		return (2);
	return (0);
}

// static void validate_walls(t_textures **texture)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	if (!(*texture)->map)
// 		ft_put_error_exit("Map is missing");
// 	while (i < (*texture)->m_height)
// 	{
// 		while (j < (*texture)->m_width)
// 		{
// 			while ((*texture)->map[i][j].ch == '1' && j < (*texture)->m_width)
// 			{
// 				j++;
// 				(*texture)->map[i][j].ch = '2';
// 			}
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// }
void	validate_map(t_node **map)
{
	if (!map)
		ft_put_error_exit("No map found");
	// flood fill etc.
}
