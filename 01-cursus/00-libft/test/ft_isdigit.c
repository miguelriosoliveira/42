#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int main() {
	int c;
	c = 'F';
	printf("   isdigit('%c'): %d\n", c,    isdigit(c));
	printf("ft_isdigit('%c'): %d\n", c, ft_isdigit(c));
	c = '2';
	printf("   isdigit('%c'): %d\n", c,    isdigit(c));
	printf("ft_isdigit('%c'): %d\n", c, ft_isdigit(c));
	c = 'f';
	printf("   isdigit('%c'): %d\n", c,    isdigit(c));
	printf("ft_isdigit('%c'): %d\n", c, ft_isdigit(c));
	c = ')';
	printf("   isdigit('%c'): %d\n", c,    isdigit(c));
	printf("ft_isdigit('%c'): %d\n", c, ft_isdigit(c));
}
