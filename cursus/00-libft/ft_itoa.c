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

static int	count_chars(int nb)
{
	long	nbr;
	int		count;

	nbr = nb;
	count = 1;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

static void	fill_str(char *str, int nb, int size)
{
	long	nbr;
	int		is_negative;

	nbr = nb;
	is_negative = nbr < 0;
	if (is_negative)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (size > is_negative)
	{
		size--;
		str[size] = nbr % 10 + '0';
		nbr /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*n_str;

	size = count_chars(n);
	n_str = ft_calloc((size + 1), sizeof(char));
	if (!n_str)
		return (NULL);
	fill_str(n_str, n, size);
	return (n_str);
}
