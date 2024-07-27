NAME = libft.a

SRC = src/*.c

OBJ = $(SRC:.c=.o)

CC = cc -Wall -Werror -Wextra
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
