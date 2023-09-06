
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*str;

	str = (char *)src;
	dest = (char *)dst;
	if (str < dest && (dest < str + len))
	{
		dest += len;
		str += len;
		while (len-- > 0)
			*--dest = *--str;
	}
	else
		ft_memcpy(dst, src, len);
	dest = NULL;
	str = NULL;
	return (dst);
}
