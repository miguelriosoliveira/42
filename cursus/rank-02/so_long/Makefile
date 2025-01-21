NAME = so_long

SRC_FILES = hooks.c print.c render.c so_long.c sprites.c utils.c validation.c
SRC = $(addprefix src/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)

SRC_FILES_BONUS = hooks_bonus.c print_bonus.c render_bonus.c so_long_bonus.c sprites_bonus.c utils_bonus.c validation_bonus.c
SRC_BONUS = $(addprefix src_bonus/, $(SRC_FILES_BONUS))
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = cc -Wall -Werror -Wextra -fsanitize=address -g3
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

all: dependencies $(NAME)

dependencies:
	$(MAKE) $(MLX_PATH)
	$(MAKE) $(LIBFT_PATH)

$(NAME): $(OBJ)
	$(CC) $(MLX_FLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) $(MLX_PATH) clean
	$(MAKE) $(LIBFT_PATH) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

test: re $(NAME)
	for file in "" invalid_nonexistant.ber maps/*; do \
		echo "-----> ./$(NAME) $$file"; \
		./$(NAME) $$file; \
	done

bonus: dependencies $(OBJ_BONUS)
	$(CC) $(MLX_FLAGS) $(OBJ_BONUS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

clean_bonus:
	$(MAKE) $(MLX_PATH) clean
	$(MAKE) $(LIBFT_PATH) clean
	$(RM) $(OBJ_BONUS)

fclean_bonus: clean_bonus
	$(MAKE) $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re_bonus: fclean_bonus bonus

test_bonus: re_bonus
	for file in "" invalid_nonexistant.ber maps_bonus/*; do \
		echo "-----> ./$(NAME) $$file"; \
		./$(NAME) $$file; \
	done

.PHONY: all dependencies $(NAME) clean fclean re bonus clean_bonus fclean_bonus re_bonus test test_bonus
