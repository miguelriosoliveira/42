/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:06:54 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/05 23:06:54 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*mapped_tab;

	mapped_tab = malloc(length * sizeof(int));
	if (!mapped_tab)
		return (NULL);
	i = 0;
	while (i < length)
	{
		mapped_tab[i] = f(tab[i]);
		i++;
	}
	return (mapped_tab);
}

/*
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

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

int	increment(int n)
{
	return (n + 1);
}

int main() {
	int tab[] = {1, 2, 3, 4, 5};
	ft_foreach(tab, 5, &ft_putnbr);
	ft_putchar('\n');
	int *new_tab = ft_map(tab, 5, &increment);
	ft_foreach(new_tab, 5, &ft_putnbr);
}
*/
