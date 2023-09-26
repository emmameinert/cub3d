
#include "../../headers/cubed.h"

void	parse_player(t_player **player)
{
	(*player)->x = (*player)->x * MINI_SIZE + PLR_SIZE;
	(*player)->y = (*player)->y * MINI_SIZE + PLR_SIZE;
	if ((*player)->dir == 'E')
		(*player)->angle = 0;
	if ((*player)->dir == 'S')
		(*player)->angle = 270;
	if ((*player)->dir == 'W')
		(*player)->angle = 180;
	if ((*player)->dir == 'N')
		(*player)->angle = 90;
	(*player)->dir_x = cos(ft_dtorad((*player)->angle));
	(*player)->dir_y = -sin(ft_dtorad((*player)->angle));
}
