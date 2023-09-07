
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*counter;
	unsigned char	*temp;

	temp = 0;
	counter = (unsigned char *)s;
	while (1)
	{
		if (*counter == (unsigned char)c)
		{
			temp = counter;
		}
		if (*counter == '\0')
		{
			break ;
		}
		counter++;
	}
	counter = NULL;
	return ((char *)temp);
}
