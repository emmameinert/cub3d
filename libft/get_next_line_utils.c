
#include "libft.h"

int	ft_findchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin_free(char *cache, char *buffer)
{
	char	*result;
	int		index_r;
	int		index_c;
	size_t	len;

	if (!cache || !buffer)
		return (NULL);
	len = (ft_strlen(cache) + ft_strlen(buffer));
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	index_r = 0;
	index_c = 0;
	while (cache[index_c] != '\0')
		result[index_r++] = cache[index_c++];
	index_c = 0;
	while (buffer[index_c] != '\0')
		result[index_r++] = buffer[index_c++];
	result[index_r] = '\0';
	free(cache);
	return (result);
}

char	*ft_init_str(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	*str = '\0';
	return (str);
}
