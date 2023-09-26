NAME = ft_tail
LIB = libft.a

SRC_DIR = src/
SRC_FILES = file.c ft_atoi.c ft_putchar.c ft_putstr.c ft_split.c ft_strcmp.c ft_strlen.c includes.c $(NAME).c
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

# test: re
# 	tail      -c 10 test/small.txt > expected.txt
# 	./$(NAME) -c 10 test/small.txt > received.txt
# 	diff -s expected.txt received.txt
# 	tail      -c 10 test/large.txt > expected.txt
# 	./$(NAME) -c 10 test/large.txt > received.txt
# 	diff -s expected.txt received.txt
# 	tail      -c 10 test/small.txt test/large.txt > expected.txt
# 	./$(NAME) -c 10 test/small.txt test/large.txt > received.txt
# 	diff -s expected.txt received.txt
# 	-tail      -c 10 test/missing.txt > expected.txt
# 	-./$(NAME) -c 10 test/missing.txt > received.txt
# 	diff -s expected.txt received.txt
# 	-tail      -c 10 test/missing.txt test/small.txt > expected.txt
# 	-./$(NAME) -c 10 test/missing.txt test/small.txt > received.txt
# 	diff -s expected.txt received.txt
# 	tail      -c10 test/small.txt > expected.txt
# 	./$(NAME) -c10 test/small.txt > received.txt
# 	diff -s expected.txt received.txt
# 	cat test/small.txt | tail      -c10 > expected.txt
# 	cat test/small.txt | ./$(NAME) -c10 > received.txt
# 	diff -s expected.txt received.txt
# 	make fclean
# 	$(RM) expected.txt received.txt
