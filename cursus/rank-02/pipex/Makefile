NAME = pipex

SRC_FILES = commands.c errors.c pipex.c utils.c
SRC = $(addprefix src/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)

CC = cc -Wall -Werror -Wextra -fsanitize=address -g3
RM = rm -rf
MAKE = make -sC

LIBFT_DIR = libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a

all: $(LIBFT_DIR) $(NAME)

$(LIBFT_DIR):
	$(MAKE) $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(MAKE) $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

test: re
	bash test/test.sh

.PHONY: all $(LIBFT_DIR) $(NAME) clean fclean re
