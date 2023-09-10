
#include "../../headers/cubed.h"

static int	valid_char(char ch)
{
	if (ch == '1' || ch == '0'
		|| ch == 'N' || ch == 'E'
		|| ch == 'W' || ch == 'S'
		|| ch == ' ')
		return (1);
	return (0);
}

void	parse_map(char *input)
{
	t_node		**coords; // TODO move to the info data struct
	static int	x;
	static int	y;

	// TODO: ignore new lines before the map
	while (*input)
	{
		if (valid_char(*input))
			ft_lstadd_back(coords, x++, y++, *input);
		else
			exit(0); // TODO call ft_puterror_exit_thingy
		input++;
	}
}
