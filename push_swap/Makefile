NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	parse_args.c parse_utils.c parse_build.c ps_split.c\
	stack_utils.c stack_utils2.c stack_utils3.c \
	op_swap.c op_push.c op_rotate.c op_rev_rotate.c \
	sort_small.c sort_small_utils.c sort_radix.c \
	indexing.c error.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re