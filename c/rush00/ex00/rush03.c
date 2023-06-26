/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:53:19 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/03 12:23:21 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_pan(int x)
{
	char	a;
	char	b;
	char	c;
	int		j;

	a = 'A';
	b = 'B';
	c = 'C';
	j = 0;
	ft_putchar(a);
	while (j < (x - 2))
	{
		ft_putchar(b);
		j++;
	}
	if (x >= 2)
		ft_putchar(c);
	ft_putchar('\n');
}

void	print_relleno(int x)
{
	int		i;
	char	b;
	char	e;

	b = 'B';
	e = ' ';
	i = 0;
	ft_putchar(b);
	while (i < (x - 2))
	{
		ft_putchar(e);
		i++;
	}
	if (x >= 2)
		ft_putchar(b);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0)
		return ;
	i = 0;
	print_pan(x);
	while (i < y - 2)
	{
		print_relleno(x);
		i++;
	}
	if (y >= 2)
		print_pan(x);
}
