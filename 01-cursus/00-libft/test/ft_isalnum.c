#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int main() {
	int c;
	c = 'F';
	printf("   isalnum('%c'): %d\n", c,    isalnum(c));
	printf("ft_isalnum('%c'): %d\n", c, ft_isalnum(c));
	c = '2';
	printf("   isalnum('%c'): %d\n", c,    isalnum(c));
	printf("ft_isalnum('%c'): %d\n", c, ft_isalnum(c));
	c = 'f';
	printf("   isalnum('%c'): %d\n", c,    isalnum(c));
	printf("ft_isalnum('%c'): %d\n", c, ft_isalnum(c));
	c = ')';
	printf("   isalnum('%c'): %d\n", c,    isalnum(c));
	printf("ft_isalnum('%c'): %d\n", c, ft_isalnum(c));
}
