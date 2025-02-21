/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:41:04 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/13 17:41:06 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	to_base(int nbr, char *base, int digits, int *counter)
{
	long	nbr_long;
	int		base_len;

	nbr_long = nbr;
	if (nbr_long < 0)
	{
		ft_putchar('-');
		nbr_long = -nbr_long;
	}
	base_len = ft_strlen(base);
	if (nbr_long >= base_len)
	{
		*counter += 1;
		to_base(nbr_long / base_len, base, digits, counter);
	}
	while (*counter < digits)
	{
		ft_putchar('0');
		*counter += 1;
	}
	ft_putchar(base[nbr_long % base_len]);
}

void	ft_putnbr_base(int nbr, char *base, int digits)
{
	int		i;
	int		base_len;
	int		is_printable;
	char	c;
	char	*forbidden_chars;

	forbidden_chars = "+-";
	base_len = ft_strlen(base);
	if (base_len < 2)
		return ;
	i = 0;
	while (base[i])
	{
		c = base[i];
		is_printable = (c >= 32 && c <= 126);
		if (!is_printable
			|| includes(c, forbidden_chars)
			|| includes(c, &base[i + 1]))
			return ;
		i++;
	}
	i = 1;
	to_base(nbr, base, digits, &i);
}
