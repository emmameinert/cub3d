
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		len;

	len = ft_strlen(s);
	new = (char *)malloc(sizeof(*new) * len + 1);
	if (!new)
	{
		return (NULL);
	}
	ft_strlcpy(new, s, len + 1);
	return (new);
}
