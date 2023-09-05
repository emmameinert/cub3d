# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emmameinert <emmameinert@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:13:53 by meskelin          #+#    #+#              #
#    Updated: 2023/09/05 14:03:23 by emmameinert      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_FILES = ft_isalpha \
ft_abs \
ft_lerp \
ft_isdigit \
ft_isascii \
ft_isalnum \
ft_isprint \
ft_tolower \
ft_toupper \
ft_memchr \
ft_memcpy \
ft_memmove \
ft_memset \
ft_memcmp \
ft_putchar_fd \
ft_strchr \
ft_strlen \
ft_strlcat \
ft_strlcpy \
ft_split \
ft_strdup \
ft_strjoin \
ft_strncmp \
ft_strnstr \
ft_strrchr \
ft_strtrim \
ft_striteri \
ft_strmapi \
ft_substr \
ft_atoi \
ft_bzero \
ft_calloc \
ft_itoa \
ft_putchar_fd \
ft_putstr_fd \
ft_putendl_fd \
ft_putnbr_fd \
get_next_line_utils \
get_next_line \
free_array \
ft_strncmp_all \

H_FILES = libft

LIB_NAME = libft.a

SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addsuffix .o, $(SRC_FILES))
B_SRC = $(addsuffix .c, $(BONUS))
HS = $(addsuffix .h, $(H_FILES))

BUILD_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	cc $(BUILD_FLAGS) -c $(SRC) -I $(HS)
	ar rc $(LIB_NAME) $(OBJ)
	ranlib $(LIB_NAME)

clean:
	rm -f $(OBJ) $(B_SRC:.c=.o)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all
