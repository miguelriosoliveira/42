/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlib.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:04:50 by mguardia          #+#    #+#             */
/*   Updated: 2023/06/18 15:07:39 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nb_long;

	nb_long = nb;
	if (nb_long < 0)
	{
		ft_putchar('-');
		nb_long = -nb_long;
	}
	if (nb_long >= 10)
	{
		ft_putnbr(nb_long / 10);
	}
	ft_putchar('0' + nb_long % 10);
}

int	is_multiple_1000(int count)
{
	int	zeros;

	zeros = 0;
	while (count != 1)
	{
		zeros++;
		count /= 10;
	}
	if (zeros % 3 == 0)
		return (0);
	return (1);
}

int	count_zeros(int count)
{
	int	zeros;

	zeros = 0;
	while (count != 1)
	{
		zeros++;
		count /= 10;
	}
	return (zeros + 1);
}
