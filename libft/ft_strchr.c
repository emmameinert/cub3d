
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (*ptr != (unsigned char)c)
	{
		if (*ptr == '\0')
		{
			break ;
		}
		ptr++;
	}
	if (*ptr == (unsigned char)c)
	{
		return ((char *)ptr);
	}
	ptr = NULL;
	return (NULL);
}
