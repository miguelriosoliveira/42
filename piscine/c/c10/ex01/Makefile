NAME = ft_cat

SRC_DIR = src/
SRC_FILES = ft_display_file.c ft_putchar.c ft_putstr.c $(NAME).c main.c
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

# test: re
# 	cat       test/1.txt > expected.txt
# 	./$(NAME) test/1.txt > received.txt
# 	diff -s expected.txt received.txt
# 	cat       test/2.txt > expected.txt
# 	./$(NAME) test/2.txt > received.txt
# 	diff -s expected.txt received.txt
# 	cat       test/1.txt test/2.txt > expected.txt
# 	./$(NAME) test/1.txt test/2.txt > received.txt
# 	diff -s expected.txt received.txt
# 	-cat       test/wrong.txt > expected.txt
# 	-./$(NAME) test/wrong.txt > received.txt
# 	diff -s expected.txt received.txt
# 	-cat       test/wrong.txt test/1.txt > expected.txt
# 	-./$(NAME) test/wrong.txt test/1.txt > received.txt
# 	diff -s expected.txt received.txt
# 	-cat       test/1.txt test/wrong.txt > expected.txt
# 	-./$(NAME) test/1.txt test/wrong.txt > received.txt
# 	diff -s expected.txt received.txt
# 	cat test/1.txt | cat       > expected.txt
# 	cat test/1.txt | ./$(NAME) > received.txt
# 	diff -s expected.txt received.txt
# 	cat test/1.txt | cat       - > expected.txt
# 	cat test/1.txt | ./$(NAME) - > received.txt
# 	diff -s expected.txt received.txt
# 	cat test/2.txt | cat       test/1.txt - > expected.txt
# 	cat test/2.txt | ./$(NAME) test/1.txt - > received.txt
# 	diff -s expected.txt received.txt
# 	# printf "" | cat       test/1.txt - <(cat       test/1.txt) test/2.txt - <(cat       test/1.txt) test/1.txt > expected.txt
# 	# printf "" | ./$(NAME) test/1.txt - <(./$(NAME) test/1.txt) test/2.txt - <(./$(NAME) test/1.txt) test/1.txt > received.txt
# 	# diff -s expected.txt received.txt
# 	make fclean
# 	$(RM) expected.txt received.txt
