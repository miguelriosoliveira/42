#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int main() {
	int c;
	c = 'F';
	printf("is '%c' alpha? %d\n", c, ft_isalpha(c));
	c = '2';
	printf("is '%c' alpha? %d\n", c, ft_isalpha(c));
	c = 'f';
	printf("is '%c' alpha? %d\n", c, ft_isalpha(c));
	c = ')';
	printf("is '%c' alpha? %d\n", c, ft_isalpha(c));
}
