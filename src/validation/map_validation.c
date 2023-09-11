
#include "../../headers/cubed.h"

int	valid_char(char ch)
{
	if (ch == '1' || ch == '0'
		|| ch == 'N' || ch == 'E'
		|| ch == 'W' || ch == 'S'
		|| ch == ' ')
		return (1);
	return (0);
}

void	validate_map(t_node **map)
{
	if (!map)
		ft_put_error_exit("No map found");
	// flood fill etc.
}
