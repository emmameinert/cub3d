
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		index;

	index = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (*s1 != '\0')
	{
		str[index++] = *(s1++);
	}
	while (*s2 != '\0')
	{
		str[index++] = *(s2++);
	}
	str[index] = '\0';
	return (str);
}
