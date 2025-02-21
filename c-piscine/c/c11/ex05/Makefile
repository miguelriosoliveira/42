NAME = do-op
LIB = libft.a

SRC_DIR = src/
SRC_FILES = ft_atoi.c io.c math.c string.c $(NAME).c
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

test: re
	printf '' > expected.txt
	./$(NAME) > received.txt
	diff -s expected.txt received.txt

	echo      2     > expected.txt
	./$(NAME) 1 + 1 > received.txt
	diff -s expected.txt received.txt

	echo      62                    > expected.txt
	./$(NAME) 42amis - --+-20toto12 > received.txt
	diff -s expected.txt received.txt

	echo      0     > expected.txt
	./$(NAME) 1 p 1 > received.txt
	diff -s expected.txt received.txt

	echo      1         > expected.txt
	./$(NAME) 1 + toto3 > received.txt
	diff -s expected.txt received.txt

	echo      4         > expected.txt
	./$(NAME) toto3 + 4 > received.txt
	diff -s expected.txt received.txt

	echo      0            > expected.txt
	./$(NAME) foo plus bar > received.txt
	diff -s expected.txt received.txt

	echo      'Stop : division by zero' > expected.txt
	./$(NAME) 25 / 0                    > received.txt
	diff -s expected.txt received.txt

	echo      'Stop : modulo by zero' > expected.txt
	./$(NAME) 25 % 0                  > received.txt
	diff -s expected.txt received.txt

	make fclean
	$(RM) expected.txt received.txt
