NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	src/check_map.c \
	src/check_map2.c \
	src/cleanup.c \
	src/error.c \
	src/flood_fill.c \
	src/hooks.c \
	src/image.c \
	src/map_read.c \
	src/render.c \
	src/utils.c \
	src/utils2.c

OBJ = $(SRC:.c=.o)

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES = -I. -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re