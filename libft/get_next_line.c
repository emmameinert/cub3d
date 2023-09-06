
#include "libft.h"

static char	*trim_cache(char *cache)
{
	char	*result;
	size_t	index_r;
	size_t	index_c;
	size_t	len;

	index_c = 0;
	len = ft_strlen(cache);
	while (cache[index_c] && cache[index_c] != '\n')
		index_c++;
	if (cache[index_c] == '\n')
		index_c++;
	result = (char *)malloc(sizeof(char) * ((len - index_c) + 2));
	if (!result)
		return (NULL);
	index_r = 0;
	while (cache[index_c] != '\0')
		result[index_r++] = cache[index_c++];
	free(cache);
	result[index_r] = '\0';
	if (result[0] == '\0')
	{
		free(result);
		return (NULL);
	}
	return (result);
}

static char	*parse_nl(char *cache)
{
	char	*result;
	size_t	cache_index;
	size_t	index;

	cache_index = 0;
	while (cache[cache_index] != '\0' && cache[cache_index] != '\n')
		cache_index++;
	result = (char *)malloc(sizeof(char) * (cache_index + 2));
	if (!result)
		return (NULL);
	index = 0;
	while (index <= cache_index && cache)
	{
		result[index] = cache[index];
		index++;
	}
	result[index] = '\0';
	if (result[0] == '\0')
	{
		free(result);
		return (NULL);
	}
	return (result);
}

static char	*read_fd(int fd, char *cache)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			break ;
		buffer[read_bytes] = '\0';
		if (!cache)
			cache = ft_init_str();
		cache = ft_strjoin_free(cache, buffer);
		if (!cache)
			break ;
		if (ft_findchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (cache);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	cache = read_fd(fd, cache);
	if (!cache)
		return (NULL);
	line = parse_nl(cache);
	cache = trim_cache(cache);
	return (line);
}
