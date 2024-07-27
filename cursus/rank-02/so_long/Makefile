NAME = so_long

SRC = src/*.c

OBJ = $(SRC:.c=.o)
LIBFT_OBJ = libft/*.o

CC = cc -Wall -Werror -Wextra
AR = ar -rcs
RM = rm -rf

all: libft $(NAME)

bonus: all

libft:
	make -C ./libft all

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ) $(LIBFT_OBJ)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	make -C ./libft clean
	$(RM) $(OBJ)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re: fclean all

ft_%:
	$(CC) test/$@.c -L. -lsolong -o test/a.out && ./test/a.out

test: re ft_printf

.PHONY: all bonus libft clean fclean re test
