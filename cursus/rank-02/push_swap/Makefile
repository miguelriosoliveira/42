NAME = push_swap

SRC_FILES = push_swap.c push.c reverse_rotate.c rotate.c sort_utils.c sort_utils2.c sort.c stack.c swap.c utils.c validation.c
SRC = $(addprefix src/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)

CC = cc -Wall -Werror -Wextra
CC += -fsanitize=address -g3
RM = rm -rf
MAKE = make -sC

LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

all: $(NAME)

$(LIBFT_LIB):
	$(MAKE) $(LIBFT_PATH)

$(NAME): $(LIBFT_LIB) $(OBJ)
	$(CC) $(LIBFT_LIB) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(MAKE) $(LIBFT_PATH) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

test: re
	bash test/test.sh

.PHONY: all clean fclean re test
