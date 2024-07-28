NAME = so_long

SRC = so_long.c

OBJ = $(SRC:.c=.o) libft/*.o

CC = cc -Wall -Werror -Wextra
AR = ar -rcs
RM = rm -rf

all: libft $(NAME)

bonus: all

libft:
	make -C ./libft all

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	make -C ./libft clean
	$(RM) $(OBJ)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re
