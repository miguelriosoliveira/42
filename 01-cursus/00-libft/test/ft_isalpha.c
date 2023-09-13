#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int main() {
	int c;
	c = 'F';
	printf("   isalpha('%c'): %d\n", c,    isalpha(c));
	printf("ft_isalpha('%c'): %d\n", c, ft_isalpha(c));
	c = '2';
	printf("   isalpha('%c'): %d\n", c,    isalpha(c));
	printf("ft_isalpha('%c'): %d\n", c, ft_isalpha(c));
	c = 'f';
	printf("   isalpha('%c'): %d\n", c,    isalpha(c));
	printf("ft_isalpha('%c'): %d\n", c, ft_isalpha(c));
	c = ')';
	printf("   isalpha('%c'): %d\n", c,    isalpha(c));
	printf("ft_isalpha('%c'): %d\n", c, ft_isalpha(c));
}
