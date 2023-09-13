cc -Wall -Wextra -Werror -c ft_*.c
ar -rcs libft.a *.o
rm *.o

# ========= to test =========
# cc -Wall -Wextra -Werror main.c -L. -lft
# ./a.out
# ./a.out test
# ./a.out "larger test"
