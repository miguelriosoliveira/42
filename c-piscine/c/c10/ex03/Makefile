NAME = ft_hexdump
LIB = libft.a

SRC_DIR = src/
SRC_FILES = file.c ft_print_memory.c ft_putchar.c ft_putnbr_base.c ft_putstr.c ft_split.c ft_strcmp.c ft_strlen.c ft_strncpy.c includes.c $(NAME).c
SRC = $(addprefix $(SRC_DIR),$(SRC_FILES))

OBJ = $(SRC:.c=.o)

CC = cc -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(LIB) $(OBJ)
	$(CC) $(SRC_DIR)main.c -L. -lft -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(LIB)

re: fclean all

%.txt: test/%.txt
	hexdump	  -C $< > expected.txt
	./$(NAME) -C $< > received.txt
	diff -s expected.txt received.txt

test: re small.txt 1024.txt 1025.txt large.txt
	hexdump	  -C test/a.txt test/B.txt > expected.txt
	./$(NAME) -C test/a.txt test/B.txt > received.txt
	diff -s expected.txt received.txt
	make fclean
	$(RM) expected.txt received.txt
