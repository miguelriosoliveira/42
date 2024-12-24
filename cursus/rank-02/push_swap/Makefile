NAME = push_swap

SRC_FILES = push_swap.c
SRC = $(addprefix src/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)

CC = cc -Wall -Werror -Wextra -fsanitize=address -g3
RM = rm -rf
MAKE = make -sC

LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

all: $(LIBFT_PATH) $(NAME)

$(LIBFT_PATH):
	$(MAKE) $(LIBFT_PATH)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) $(LIBFT_PATH) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(LIBFT_PATH) $(NAME) clean fclean re
