/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:52:38 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/02 14:52:39 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	end_pos;
	int	i;

	end_pos = size - 1;
	i = 0;
	while (i < size / 2)
	{
		ft_swap(&tab[i], &tab[end_pos - i]);
		i++;
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
*/