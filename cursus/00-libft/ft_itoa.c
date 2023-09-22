/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:05:11 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/13 19:05:11 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int	count_chars(int nb)
{
	long	nbr;
	int		count;

	nbr = nb;
	count = 1;

	printf("nbr: %ld\n", nbr);

	if (nbr < 0)
	{
		printf("is negative!\n");
		printf("nbr: %ld\n", nbr);
		count++;
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		printf("nbr: %ld\n", nbr);
		count++;
		nbr /= 10;
	}

		printf("nbr: %ld\n", nbr);

	return (count);
}

char	*ft_itoa(int n)
{
	printf("char_count: %d\n", count_chars(n));
	return "";
}
