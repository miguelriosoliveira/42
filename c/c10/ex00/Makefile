NAME = ft_display_file

SRC_DIR = src/
SRC_FILES = ft_putchar.c ft_putstr.c ft_display_file.c main.c
SRC = $(addprefix $(SRC_DIR),$(SRC_FILES))

OBJ = $(SRC:.c=.o)

CC = cc -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: re
	printf     "" > expected.txt
	-./$(NAME)    > received.txt
	diff -s expected.txt received.txt
	cat       test/small.txt > expected.txt
	./$(NAME) test/small.txt > received.txt
	diff -s expected.txt received.txt
	cat       test/large.txt > expected.txt
	./$(NAME) test/large.txt > received.txt
	diff -s expected.txt received.txt
	printf                                "" > expected.txt
	-./$(NAME) test/small.txt test/large.txt > received.txt
	diff -s expected.txt received.txt
	make fclean
	$(RM) expected.txt received.txt
