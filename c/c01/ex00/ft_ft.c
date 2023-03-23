#include <stdio.h>

void ft_ft(int *nbr) {
	*nbr = 42;
}

int main(void) {
	int nbr = 10;
	printf("Antes: %d\n", nbr);
	ft_ft(&nbr);
	printf("Luego: %d\n", nbr);
	return 0;
}

