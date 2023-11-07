# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 11:50:43 by meskelin          #+#    #+#              #
#    Updated: 2023/10/24 11:50:43 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT_PATH = ./libft
MLX_PATH = ./mlx

SRC_INT =	init_mlx \
			init_player \
			init_info \
			init_ray

SRC =	cub3d \
		main

SRC_MATH =	angle \
			color

SRC_RCST =	cast_rays

SRC_PRS =	file_parsing \
			matrix_parsing \
			texture_parsing \
			array_parsing \
			player_parsing \
			map_parsing

SRC_LL =	ft_lstsize \
			ft_lstclear \
			ft_lstiterate \
			ft_lstlast \
			ft_lstnew \
			ft_lstfree \
			ft_lstadd_back

SRC_UTLS =	file \
			hook \
			move \
			exit

SRC_VLD =	map_validation \
			texture_validation \
			flood_fill

SRC_RNDR =	mlx_handler \
			put_pixel \
			draw_minimap \
			draw_background \
			draw_line \
			draw_player \
			draw_color \
			draw_wall \
			draw_maze \
			draw_rays \
			render

HDRS =	cubed \
		lst

BUILD_FLAGS = -Wall -Wextra -Werror -O3

SRC_INT_PRE = $(addprefix ./src/initializing/, $(SRC_INT))
SRC_INT_SUFF = $(addsuffix .c, $(SRC_INT_PRE))
SRC_RCST_PRE = $(addprefix ./src/raycasting/, $(SRC_RCST))
SRC_RCST_SUFF = $(addsuffix .c, $(SRC_RCST_PRE))
SRC_MATH_PRE = $(addprefix ./src/math/, $(SRC_MATH))
SRC_MATH_SUFF = $(addsuffix .c, $(SRC_MATH_PRE))
SRC_PRE = $(addprefix ./src/, $(SRC))
SRC_SUFF = $(addsuffix .c, $(SRC_PRE))
SRC_LL_PRE = $(addprefix ./src/linked_list/, $(SRC_LL))
SRC_LL_SUFF = $(addsuffix .c, $(SRC_LL_PRE))
SRC_PRS_PRE = $(addprefix ./src/parsing/, $(SRC_PRS))
SRC_PRS_SUFF = $(addsuffix .c, $(SRC_PRS_PRE))
SRC_UTLS_PRE = $(addprefix ./src/utils/, $(SRC_UTLS))
SRC_UTLS_SUFF = $(addsuffix .c, $(SRC_UTLS_PRE))
SRC_VLD_PRE = $(addprefix ./src/validation/, $(SRC_VLD))
SRC_VLD_SUFF = $(addsuffix .c, $(SRC_VLD_PRE))
SRC_RNDR_PRE = $(addprefix ./src/rendering/, $(SRC_RNDR))
SRC_RNDR_SUFF = $(addsuffix .c, $(SRC_RNDR_PRE))

HPRE = $(addprefix ./headers/, $(HDRS))
HSUFF = $(addsuffix .h, $(HPRE))

.PHONY = all
all: $(NAME)

$(NAME): $(SRC_LL_SUFF) $(SRC_MATH_SUFF) $(SRC_RCST_SUFF) $(SRC_INT_SUFF) $(SRC_VLD_SUFF) $(SRC_RNDR_SUFF) $(SRC_UTLS_SUFF) $(SRC_PRS_SUFF) $(SRC_SUFF) $(HSUFF)
		make -C $(LIBFT_PATH)
		make -C $(MLX_PATH)
		cc $(BUILD_FLAGS) $(SRC_LL_SUFF) $(SRC_MATH_SUFF) $(SRC_RCST_SUFF) $(SRC_INT_SUFF) $(SRC_VLD_SUFF) $(SRC_RNDR_SUFF) $(SRC_PRS_SUFF) \
		$(SRC_UTLS_SUFF) $(SRC_SUFF) \
		-Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.PHONY: clean
clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)
	rm -f $(SRCSO)

.PHONY: fclean
fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

.PHONY: re
re: fclean all
