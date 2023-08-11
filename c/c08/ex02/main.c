#include <stdio.h>
#include "ft_abs.h"

int main() {
	int value;
	value = -5;
	printf("ABS(%d): %d\n", value, ABS(value));
	value = 5;
	printf("ABS(%d): %d\n", value, ABS(value));
	value = 0;
	printf("ABS(%d): %d\n", value, ABS(value));
	return 0;
}
