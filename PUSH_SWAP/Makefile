# Program name
NAME	= push_swap
BONUS	= checker

# Compiler options
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g 

# program files
SRC		= 	actions/push.c \
			actions/rev_rotate.c \
			actions/rotate.c \
			actions/sort_three.c \
			actions/swap.c \
			algo/assign_position_target.c \
			algo/define_cost.c \
			algo/move_nodes_to_top.c \
			algo/push_swap.c \
			debbug_ps.c \
			initList.c \
			main.c \
			split.c \
			utils_ps.c \

OBJ		= $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)


# Colors
RESET = \033[0m
BOLD = \033[1m
RED = \033[91m
GREEN = \033[92m
YELLOW = \033[33m
ORANGE = \033[93m
BLUE = \033[94m

# Compiling PUSH_SWAP
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -g
	@echo "✨ 🚀 CONVERT SOURCE CODE TO MACHINE CODE BINARY FORMAT 🚀 ✨"


clean:
	@echo "🧹 ALL FILES HAVE BEEN DELETED 🧹"
	@rm -rf $(OBJ)


fclean: clean
	@echo "🧹 ALL FILES HAVE BEEN DELETED 🧹"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus