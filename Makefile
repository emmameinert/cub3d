
NAME = cub3D

LIBFT_PATH = ./libft

BUILD_FLAGS = -Wall -Wextra -Werror

SRC =	input \
		cub3D \
		input_utils \
		texture_validation \

SRC_PRS = map_parsing

SRC_LL =	ft_lstsize \
			ft_lstclear \
			ft_lstiterate \
			ft_lstlast \
			ft_lstnew \
			ft_lstadd_back

HDRS =	cubed \
		lst

SRC_PRE = $(addprefix ./src/, $(SRC))
SRC_SUFF = $(addsuffix .c, $(SRC_PRE))
SRC_LL_PRE = $(addprefix ./src/linked_list/, $(SRC_LL))
SRC_LL_SUFF = $(addsuffix .c, $(SRC_LL_PRE))
SRC_PRS_PRE = $(addprefix ./src/parsing/, $(SRC_PRS))
SRC_PRS_SUFF = $(addsuffix .c, $(SRC_PRS_PRE))

HPRE = $(addprefix ./headers/, $(HDRS))
HSUFF = $(addsuffix .h, $(HPRE))

.PHONY = all
all: $(NAME)

$(NAME): main.c $(SRC_SUFF) $(SRC_LL_SUFF) $(SRC_PRS_SUFF) $(HSUFF)
		make -C $(LIBFT_PATH)
		cc $(BUILD_FLAGS) $(SRC_LL_SUFF) $(SRC_PRS_SUFF) $(SRC_SUFF) main.c -Llibft -lft -o $(NAME)

.PHONY: clean
clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(SRCSO)

.PHONY: fclean
fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

.PHONY: re
re: fclean all

