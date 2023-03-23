#include <stdio.h>

void print_array(int* array, int size) {
	printf("[");
	
	int i = 0;
	while (i < size) {
		printf("%d", array[i]);
		if (i < size-1) {
			printf(", ");
		}
		i++;
	}

	printf("]");
}

void ft_swap(int* a, int* b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

void ft_rev_int_tab(int *tab, int size) {
	int end_pos = size-1;
	int i = 0;
	while (i < size / 2) {
		ft_swap(&tab[i], &tab[end_pos-i]);
		i++;
	}
}

int main(void) {
	int tab[] = {1, 2, 3, 4, 5};
	int size = 5;
	
	printf("Antes: ");
	print_array(tab, size);
	printf("\n");
	
	ft_rev_int_tab(tab, size);
	
	printf("Luego: ");
	print_array(tab, size);
	printf("\n");

	return 0;
}

