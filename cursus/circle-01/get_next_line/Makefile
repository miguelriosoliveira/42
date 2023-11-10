NAME = libgnl.a

SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

CC = cc -Wall -Werror -Wextra
BUFFER_FLAG = -D BUFFER_SIZE
AR = ar -rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ) $(LIBFT_OBJ)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

size_%:
	$(CC) $(BUFFER_FLAG)=$@ -L. -lgnl test/get_next_line.c -o test/a.out
	./test/a.out file.txt

test: re size_invalid size_1 size_10 size_9999 size_10000000
