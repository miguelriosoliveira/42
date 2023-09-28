NAME = libftprintf.a

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)
LIBFT_OBJ = libft/*.o

CC = cc -Wall -Werror -Wextra
AR = ar -rcs
RM = rm -rf

all: libft $(NAME)

libft:
	make -C ./libft all

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ) $(LIBFT_OBJ)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

ft_%:
	$(CC) test/$@.c -L. -lftprintf -o test/a.out && ./test/a.out

test: re ft_printf

.PHONY: all libft clean fclean re test
