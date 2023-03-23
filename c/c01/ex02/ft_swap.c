#include <stdio.h>

void ft_swap(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

int main(void) {
	int a = 11;
	int b = 22;
	printf("Antes: %d %d\n", a, b);
	ft_swap(&a, &b);
	printf("Luego: %d %d\n", a, b);

	return 0;
}

