NAME = ft_display_file

SRC_DIR = src/
SRC_FILES = ft_putchar.c ft_putstr.c ft_display_file.c main.c
SRC = $(addprefix $(SRC_DIR),$(SRC_FILES))

OBJ = $(SRC:.c=.o)

CC = cc -Wall -Wextra -Werror
RM = rm -rf

all:
	$(CC) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# test: re
# 	./$(NAME)
# 	./$(NAME) test/1.txt
# 	./$(NAME) test/2.txt
# 	./$(NAME) test/1.txt test/2.txt
