
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (len > 0 && haystack[i] != '\0')
	{
		while (needle[j] == haystack[i + j] && len > 0)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
			len--;
		}
		len += j;
		j = 0;
		i++;
		len--;
	}
	return (NULL);
}
