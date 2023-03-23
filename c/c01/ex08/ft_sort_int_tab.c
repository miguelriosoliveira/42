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

void ft_sort_int_tab(int *tab, int size) {
	int swap_count;
	do {
		swap_count = 0;
		int i = 0;
		while (i < size-1) {
			if (tab[i] > tab[i+1]) {
				ft_swap(&tab[i], &tab[i+1]);
				swap_count++;
			}
			i++;
		}
	} while (swap_count > 0);
}

int main(void) {
	int tab[] = {5, 4, 3, 2, 1};
	int size = 5;

	printf("Antes: ");
	print_array(tab, size);
	printf("\n");

	ft_sort_int_tab(tab, size);

	printf("Luego: ");
	print_array(tab, size);
	printf("\n");

	return 0;
}

