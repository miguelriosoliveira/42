NAME = ft_cat

SRC_DIR = src/
SRC_FILES = ft_putstr.c ft_display_file.c $(NAME).c main.c
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
# 	./$(NAME) test/1.txt
# 	./$(NAME) test/2.txt
# 	./$(NAME) test/1.txt test/2.txt
# 	echo "testint stdinput 1" | ./$(NAME)
# 	echo "testint stdinput 2" | ./$(NAME) -
# 	# ./$(NAME) test/1.txt - test/2.txt - test/3.txt
# 	make fclean
