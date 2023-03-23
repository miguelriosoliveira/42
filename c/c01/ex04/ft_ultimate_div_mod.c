#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b) {
	int div = *a / *b;
	int mod = *a % *b;
	*a = div;
	*b = mod;
}

int main(void) {
	int a = 7;
	int b = 3;

	printf("Antes:\na: %d, b: %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("Luego:\na: %d, b: %d\n", a, b);

	return 0;
}

