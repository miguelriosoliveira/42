/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:29:50 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/15 18:29:52 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
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
		printf("ft_recursive_power(%2d, %2d)", nb, power);
		printf(": %d\n\n", ft_recursive_power(nb, power));
		nb++;
		power++;
	}
}
*/