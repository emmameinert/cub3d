
NAME = cub3D

LIBFT_PATH = ./libft

BUILD_FLAGS = -Wall -Wextra -Werror

SRC = input \
		cub3D \
		input_utils \
		texture_validation \

HDRS = cubed \

SRC_PRE = $(addprefix ./src/, $(SRC))
SRC_SUFF = $(addsuffix .c, $(SRC_PRE))
HPRE = $(addprefix ./headers/, $(HDRS))
HSUFF = $(addsuffix .h, $(HPRE))

.PHONY = all
all: $(NAME)

$(NAME):
		make -C $(LIBFT_PATH)
		cc $(BUILD_FLAGS) $(SRC_SUFF) main.c -Llibft -lft -o $(NAME)

.PHONY: clean
clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(GNL_OBJ)
	rm -f $(SRCSO)

.PHONY: fclean
fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

.PHONY: re
re: fclean all

