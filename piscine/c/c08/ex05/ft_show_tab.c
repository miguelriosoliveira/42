/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:21:06 by mrios-es          #+#    #+#             */
/*   Updated: 2023/08/12 14:21:06 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ex04/ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
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
		ft_putnbr(nb_long / 10);
	ft_putchar('0' + nb_long % 10);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int			i;
	t_stock_str	stock;

	i = 0;
	while (par[i].str)
	{
		stock = par[i];
		ft_putstr(stock.str);
		ft_putchar('\n');
		ft_putnbr(stock.size);
		ft_putchar('\n');
		ft_putstr(stock.copy);
		ft_putchar('\n');
		i++;
	}
}

/*
struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
int main(int argc, char **argv) {
	t_stock_str *stocks;
	stocks = ft_strs_to_tab(argc, argv);
	stocks[0].copy[0] = '#'; // change the firsgt letter of the program's name
	ft_show_tab(stocks);
	return 0;
}
*/
