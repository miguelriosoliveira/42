/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:08:18 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/01 19:23:19 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

/*
int main(void) {
	ft_putnbr(2);
	ft_putchar('\n');
	
	ft_putnbr(42);
	ft_putchar('\n');
	
	ft_putnbr(-242);
	ft_putchar('\n');
	
	ft_putnbr(12345);
	ft_putchar('\n');
	
	ft_putnbr(2147483647);
	ft_putchar('\n');
	
	ft_putnbr(-2147483647);
	ft_putchar('\n');
	
	ft_putnbr(-2147483648);
	ft_putchar('\n');
	return 0;
}
*/
