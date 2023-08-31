
NAME = cub3D

LIBFT_PATH = ./libft

BUILD_FLAGS = -Wall -Wextra -Werror

SRC =

HDRS =	get_next_line

GNL_SRC =	get_next_line_utils
			get_next_line

SRC_PRE = $(addprefix ./, $(SRC_SRC))
SRC_SUFF = $(addsuffix .c, $(SRC_PRE))
HPRE = $(addsuffix ./headers/, $(HDRS))
HSUFF = $(addsuffix .h, $(HPRE))

GNL_PRE = $(addprefix ./get_next_line/, $(GNL_SRC))
GNL_SUFF = $(addsuffix .c, $(GNL_PRE))
GNL_OBJ = $(addsuffix .o, $(GNL_PRE))

.PHONY = all
all: $(NAME)

$(NAME): main.c $(SRC_SUFF) $(HSUFF) $(GNL_SUFF)
	make -C $(LIBFT_PATH) \
	cc $(BUILD_FLAGS) $(GNL_SUFF) $(SRC_SUFF) \
	-L $(LIBFT_PATH) -lft main.c -I $(HSUFF)

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

