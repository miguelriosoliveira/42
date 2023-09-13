#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int main() {
	int c;
	c = 'F';
	printf("   isascii('%c'): %d\n", c,    isascii(c));
	printf("ft_isascii('%c'): %d\n", c, ft_isascii(c));
	c = '2';
	printf("   isascii('%c'): %d\n", c,    isascii(c));
	printf("ft_isascii('%c'): %d\n", c, ft_isascii(c));
	c = 'f';
	printf("   isascii('%c'): %d\n", c,    isascii(c));
	printf("ft_isascii('%c'): %d\n", c, ft_isascii(c));
	c = ')';
	printf("   isascii('%c'): %d\n", c,    isascii(c));
	printf("ft_isascii('%c'): %d\n", c, ft_isascii(c));
	c = 127;
	printf("   isascii('%c'): %d\n", c,    isascii(c));
	printf("ft_isascii('%c'): %d\n", c, ft_isascii(c));
	c = 128;
	printf("   isascii('%c'): %d\n", c,    isascii(c));
	printf("ft_isascii('%c'): %d\n", c, ft_isascii(c));
}
