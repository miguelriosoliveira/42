NAME = so_long

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
MLX_LIB = $(MLX_PATH)libmlx_$(UNAME).a
ifeq ($(UNAME), Linux)
	INCLUDES = -Imlx -I/usr/include
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	INCLUDES = -Imlx -I/opt/X11/include
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

all: $(MLX_LIB) $(LIBFT_LIB) $(NAME)

$(MLX_LIB):
	$(MAKE) $(MLX_PATH)

$(LIBFT_LIB):
	$(MAKE) $(LIBFT_PATH)

%.o: %.c
	$(CC) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(MLX_FLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

clean:
	$(MAKE) $(MLX_PATH) clean
	$(MAKE) $(LIBFT_PATH) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

test: re $(NAME)
	for file in "" invalid_nonexistant.ber $(wildcard maps/*); do \
		echo "Running: ./$(NAME) $$file"; \
		./$(NAME) $$file; \
	done

.PHONY: all $(MLX_LIB) $(LIBFT_LIB) $(NAME) clean fclean re test
