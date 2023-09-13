#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int main() {
	int c;
	c = 'F';
	printf("   isprint('%c'): %d\n", c,    isprint(c));
	printf("ft_isprint('%c'): %d\n", c, ft_isprint(c));
	c = '2';
	printf("   isprint('%c'): %d\n", c,    isprint(c));
	printf("ft_isprint('%c'): %d\n", c, ft_isprint(c));
	c = 'f';
	printf("   isprint('%c'): %d\n", c,    isprint(c));
	printf("ft_isprint('%c'): %d\n", c, ft_isprint(c));
	c = ')';
	printf("   isprint('%c'): %d\n", c,    isprint(c));
	printf("ft_isprint('%c'): %d\n", c, ft_isprint(c));
	c = 31;
	printf("   isprint('%c'): %d\n", c,    isprint(c));
	printf("ft_isprint('%c'): %d\n", c, ft_isprint(c));
	c = 32;
	printf("   isprint('%c'): %d\n", c,    isprint(c));
	printf("ft_isprint('%c'): %d\n", c, ft_isprint(c));
	c = 127;
	printf("   isprint('%c'): %d\n", c,    isprint(c));
	printf("ft_isprint('%c'): %d\n", c, ft_isprint(c));
	c = 128;
	printf("   isprint('%c'): %d\n", c,    isprint(c));
	printf("ft_isprint('%c'): %d\n", c, ft_isprint(c));
}
