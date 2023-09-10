#include "libft.h"

void ft_put_error_exit(char *msg)
{
    ft_putstr_fd("Error\n", 2);
    ft_putendl_fd(msg, 2);
    exit(1);
}