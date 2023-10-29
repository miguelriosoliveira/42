NAME = libftprintf.a

SRC = flags.c ft_printf.c print_char.c print_nbr.c print_ptr.c print_str.c utils_number.c utils_print.c

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
	$(CC) test/$@.c -L. -lftprintf -o test/a.out && ./test/a.out

test: re ft_printf

.PHONY: all libft clean fclean re test
