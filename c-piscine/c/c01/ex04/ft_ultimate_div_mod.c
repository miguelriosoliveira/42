/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:43:33 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/02 14:43:37 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/*
int main(void) {
	int a = 7;
	int b = 3;

	printf("Antes:\na: %d, b: %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("Luego:\na: %d, b: %d\n", a, b);

	return 0;
}
*/