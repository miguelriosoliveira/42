/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:56:37 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/02 14:56:39 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	swap_count;
	int	i;

	swap_count = 1;
	while (swap_count > 0)
	{
		swap_count = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				swap_count++;
			}
			i++;
		}
	}
}

/*
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
*/