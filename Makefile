NAME = push_swap

CHECKERS_DIR = checkers
CHECKER = check_arguments.c
CHECKER_PATH = $(addprefix $(CHECKERS_DIR)/, $(CHECKER))

STACK_DIR = stack
STACK = stack_create.c stack_clean.c  node_create.c add_node.c create_stacks.c
STACK+= clean_struct.c fill_stack.c
STACK_PATH = $(addprefix $(STACK_DIR)/, $(STACK))

SORT_DIR = sort
SORT = is_sorted_ascending.c recursion_sort_a.c
SORT+= recursion_sort_b.c get_average_num.c sort_first_three_nodes.c
SORT+= reverse_sort_three_nodes.c sort_three_nodes_stack.c find_values.c
SORT+= sort_five_nodes_stack.c sort_four_nodes_stack.c
SORT_PATH = $(addprefix $(SORT_DIR)/, $(SORT))

MOVES_DIR = moves
MOVES = swap.c rotate_top_to_bottom.c rotate_bottom_to_top.c push.c
MOVES+= single_moves.c double_moves.c
MOVES_PATH = $(addprefix $(MOVES_DIR)/, $(MOVES))

SRC = main.c $(STACK_PATH) $(SORT_PATH) $(MOVES_PATH) $(CHECKER_PATH)
SRC_DIR = sources

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_DIR = objects


LIBFT_DIR = Libft
LIB = -L$(LIBFT_DIR) -lft
INC = -I includes -I $(LIBFT_DIR)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

MKD = mkdir -p $(@D)
RM = rm -rf

.DEFAULT_GOAL = all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKD)
	$(CC) $(CFLAGS) $(INC) -c  $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(INC)  -o $(NAME)
clean:
		make -C Libft clean
		$(RM) $(OBJ_DIR)

fclean: clean
		make -C Libft fclean
		$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
