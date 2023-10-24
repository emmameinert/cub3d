/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:47:12 by meskelin          #+#    #+#             */
/*   Updated: 2023/10/24 13:15:58 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 30

int		ft_abs(int value);
double	ft_lerp(int left, int right);
int		ft_findchr(char *str, char c);
char	*ft_strjoin_free(char *cache, char *buffer);
char	*ft_init_str(void);
char	*get_next_line(int fd);

void	free_char_array(char **str);
int		ft_isalpha(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_atoi(const char *str);
int		ft_atoui(const char *str);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void	*b, int c, size_t len);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strncmp_all(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
size_t	ft_strlcpy(char *dst, const char *src,
			size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src,
			size_t dstsize);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_put_error_exit(char *msg);
int		ft_dabs(double value);

#endif
