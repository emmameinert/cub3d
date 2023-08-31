# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 17:41:46 by meskelin          #+#    #+#              #
#    Updated: 2023/03/24 10:24:51 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

BUILD_FLAGS = -Wall -Wextra -Werror

SRC =

HDRS =

SRC_PRE = $(addprefix ./, $(SRC_SRC))
SRC_SUFF = $(addsuffix .c, $(SRC_PRE))
HPRE = $(addsuffix ./headers/, $(HDRS))
HSUFF = $(addsuffix .h, $(HPRE))

.PHONY = all
all: $(NAME)

$(NAME): main.c $(SRC_SUFF) $(HSUFF)
	cc $(BUILD_FLAGS) $(SRC_SUFF) main.c -I $(HSUFF)

.PHONY: clean
clean:
	rm -f $(SRCSO)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

