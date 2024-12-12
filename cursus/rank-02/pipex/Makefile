NAME = pipex

SRC_FILES = pipex.c utils.c
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
	-./pipex || (echo "✅ it should fail by missing arguments (error code $$?)")
	@echo ----
	-./pipex infile
	@echo ----
	-./pipex infile "ls -l"
	@echo ----
	-./pipex infile "ls -l" "wc -l"
	@echo ----
	-./pipex test/infile "lssss -l" "wc -l" test/outfile1
	@echo ----
	-./pipex test/non-existent-file "ls -l" "wc -l" test/outfile1
	@echo ----
	-./pipex test/invalid_permission_read_infile "ls -l" "wc -l" test/outfile1
	@echo ----
	./pipex test/infile "ls -l" "wc -l"  test/outfile1 \
	  &&  < test/infile  ls -l | wc -l > test/outfile2 \
	  &&  diff -s test/outfile1 test/outfile2
	@echo ----
	./pipex test/infile_cat "cat" "wc -l"  test/outfile1 \
	  &&  < test/infile_cat  cat | wc -l > test/outfile2 \
	  &&  diff -s test/outfile1 test/outfile2

.PHONY: all $(LIBFT_DIR) $(NAME) clean fclean re
