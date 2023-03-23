#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod) {
	*div = a / b;
	*mod = a % b;
}

int main(void) {
	int a = 7;
	int b = 3;
	int div;
	int mod;

	ft_div_mod(a, b, &div, &mod);
	printf("%d / %d = %d\n", a, b, div);
	printf("%d %% %d = %d\n", a, b, mod);
	
	return 0;
}

