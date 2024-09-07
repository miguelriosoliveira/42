NAME = so_long

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

SRC_ = so_long.c hooks.c render.c sprites.c
SRC = $(addprefix src/, $(SRC_))
OBJ = $(SRC:.c=.o)

CC = cc -Wall -Werror -Wextra
AR = ar -rcs
RM = rm -rf
MAKE = make -sC

LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

UNAME = $(shell uname)
MLX_PATH = mlx/
MLX_LIB = $(MLX_PATH)/libmlx_$(UNAME).a
ifeq ($(UNAME), Linux)
	INCLUDES = -Imlx -I/usr/include
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	INCLUDES = -Imlx -I/opt/X11/include
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

all: $(MLX_LIB) $(LIBFT_LIB) $(NAME)

$(MLX_LIB):
	printf $(B)"Compiling mlx..."$(X)
	$(MAKE) $(MLX_PATH)
	echo $(G)"✅ Finished!"$(X)

$(LIBFT_LIB):
	printf $(B)"Compiling libft..."$(X)
	$(MAKE) $(LIBFT_PATH)
	echo $(G)" ✅ Finished!"$(X)

%.o: %.c
	printf $(Y)"Compiling [$<]..."$(X)
	$(CC) $(INCLUDES) -c $< -o $@
	echo $(G)" ✅ Finished!"$(X)

$(NAME): $(OBJ)
	printf $(Y)"Compiling [$(NAME)]..."$(X)
	$(CC) $(MLX_FLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)
	echo $(G)" ✅ Finished!"$(X)

clean:
	printf $(B)"Cleaning mlx..."$(X)
	$(MAKE) $(MLX_PATH) clean
	echo $(G)" ✅ Finished!"$(X)
	printf $(B)"Cleaning libft..."$(X)
	$(MAKE) $(LIBFT_PATH) clean
	echo $(G)" ✅ Finished!"$(X)
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

test: re $(NAME)
	./$(NAME) maps/map1.ber
	./$(NAME) maps/map2.ber

.PHONY: all $(MLX_LIB) $(LIBFT_LIB) $(NAME) clean fclean re test

.SILENT:
