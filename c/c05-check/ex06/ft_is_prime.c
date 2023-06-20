/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:31:30 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/19 18:31:32 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h>
int main() {
	int nb = 0;
	int result = 0;
	while (nb < 100) {
		result = ft_is_prime(nb);
		if (result)
			printf("%3d is prime\n", nb);
		nb++;
	}
	nb = 999983; // largest prime number under 1000000
	printf("%3d is prime? %s\n", nb, ft_is_prime(999983) ? "yes" : "no");
}
*/