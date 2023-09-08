
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	int				index;

	index = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (!ptr1 && !ptr2 && n > 0)
	{
		return (0);
	}
	while (index < (int)n)
	{
		if (ptr1[index] != ptr2[index])
		{
			return (ptr1[index] - ptr2[index]);
		}
		index++;
	}
	return (0);
}
