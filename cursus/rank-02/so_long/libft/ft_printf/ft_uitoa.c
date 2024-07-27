/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:05:11 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/13 19:05:11 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_chars(unsigned long nb, char *base)
{
	int		count;
	size_t	base_len;

	count = 1;
	base_len = ft_strlen(base);
	while (nb >= base_len)
	{
		count++;
		nb /= base_len;
	}
	return (count);
}

static void	fill_str(char *str, unsigned long nb, int size, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	while (size > 0)
	{
		size--;
		str[size] = base[nb % base_len];
		nb /= base_len;
	}
}

char	*ft_uitoa(unsigned long n, char *base)
{
	int		size;
	char	*n_str;

	size = count_chars(n, base);
	n_str = ft_calloc((size + 1), sizeof(char));
	if (!n_str)
		return (NULL);
	fill_str(n_str, n, size, base);
	return (n_str);
}
