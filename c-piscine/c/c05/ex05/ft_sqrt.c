/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:50:15 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/16 14:50:17 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	result;

	if (nb == 1)
		return (1);
	result = nb / 2;
	while (result > 0 && result * result > nb)
	{
		result += nb / result;
		result /= 2;
	}
	if (result * result == nb)
		return (result);
	return (0);
}

/*
#include <stdio.h>
int main() {
	int nb = 0;
	int result = 0;
	while (nb < 1000) {
		result = ft_sqrt(nb);
		if (result)
			printf("ft_sqrt(%3d): %d\n", nb, result);
		nb++;
	}
	printf("%d\n", ft_sqrt(4000000));
}
*/