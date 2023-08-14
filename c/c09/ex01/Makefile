NAME = libft.a

SRC_DIR = srcs/
SRC_FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRC = $(addprefix $(SRC_DIR),$(SRC_FILES))

OBJ = $(SRC:.c=.o)

CC = cc -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# test: re
# 	$(CC) main.c -L. -lft
# 	./a.out
# 	./a.out test
# 	./a.out "larger test"
# 	make fclean
