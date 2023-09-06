
#include "libft.h"

static int	ft_istrimmable(char c, char const *s2)
{
	while (*s2)
	{
		if (c == *s2)
			return (1);
		s2++;
	}
	return (0);
}

static char	*ft_return_empty(char *str)
{
	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

static size_t	ft_find_first(char const *s1, int first, char const *set)
{
	while (ft_istrimmable(s1[first], set))
		first++;
	return (first);
}

static size_t	ft_find_last(char const *s1, int last, char const *set)
{
	if (ft_strlen(set) == 0)
		return (last);
	while (ft_istrimmable(s1[last], set))
		last--;
	return (last);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;
	size_t	first;
	size_t	last;

	first = 0;
	last = 0;
	str = NULL;
	if (!set || !s1)
		return (NULL);
	len = ft_strlen(s1);
	first = ft_find_first(s1, first, set);
	last = len - 1;
	if (first >= len || len == 0)
		return (ft_return_empty(str));
	last = ft_find_last(s1, last, set);
	len = last - first + 1;
	last = 0;
	str = (char *)malloc(sizeof(*str) * len + 1);
	if (!str)
		return (NULL);
	while (last < len)
		str[last++] = s1[first++];
	str[last] = '\0';
	return (str);
}
