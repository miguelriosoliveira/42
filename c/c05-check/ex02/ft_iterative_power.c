/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:05:58 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/15 18:06:00 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = 1;
	while (power)
	{
		result *= nb;
		power--;
	}
	return (result);
}

/*
#include <math.h>
#include <stdio.h>

int main() {
	int nb = -2;
	int power = -2;
	while (nb <= 10) {
		printf("             pow  (%2d, %2d)", nb, power);
		printf(": %ld\n", (long)pow  (nb, power));
		printf("ft_iterative_power(%2d, %2d)", nb, power);
		printf(": %d\n\n", ft_iterative_power(nb, power));
		nb++;
		power++;
	}
}
*/