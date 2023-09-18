
#include "../headers/cubed.h"

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		ft_put_error_exit("Expecting a filename as argument");
	else if (argv[1][0] == '\0')
		return (0);
	else
		run_program(argv);
	return (0);
}
