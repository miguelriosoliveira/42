NAME = so_long

SRC = so_long.c hooks.c render.c sprites.c
OBJ = $(SRC:.c=.o) libft/*.o

CC = cc -Wall -Werror -Wextra
AR = ar -rcs
RM = rm -rf

LIBFT_DIR = libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a

UNAME = $(shell uname)
MLX_DIR = mlx/
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
ifeq ($(UNAME), Linux)
	INCLUDES = -Imlx -I/usr/include
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	INCLUDES = -Imlx -I/opt/X11/include
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

all: $(MLX_LIB) $(LIBFT_LIB) $(NAME)

$(MLX_LIB):
	echo "Compiling mlx..."
	make -C $(MLX_DIR)

$(LIBFT_LIB):
	echo "Compiling libft..."
	make -C $(LIBFT_DIR)

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(NAME): $(OBJ)
	$(CC) $(MLX_FLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

# %.o: %.c
# 	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

%.o: %.c
	$(CC) $(INCLUDES) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

test: re $(NAME)
	./$(NAME) maps/map1.ber

.PHONY: all libft clean fclean re test
