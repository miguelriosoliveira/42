/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:06:28 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/15 17:06:30 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	result = 1;
	while (nb)
	{
		result *= nb;
		nb--;
	}
	return (result);
}

/*
#include <stdio.h>

int main() {
	int nb = 0;
	while (nb <= 10) {
		printf("ft_iterative_factorial(%2d): %d\n", nb, ft_iterative_factorial(nb));
		nb++;
	}
}
*/