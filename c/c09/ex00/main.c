#include <stdio.h>

void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("missing an argument\n");
		return 0;
	}
	printf("argv[1]: \"%s\" (length: %d)\n", argv[1], ft_strlen(argv[1]));
	return 0;
}
