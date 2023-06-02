/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:37:28 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/02 14:37:32 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

/*
int main(void) {
	int a = 11;
	int b = 22;
	printf("Antes: %d %d\n", a, b);
	ft_swap(&a, &b);
	printf("Luego: %d %d\n", a, b);

	return 0;
}
*/
