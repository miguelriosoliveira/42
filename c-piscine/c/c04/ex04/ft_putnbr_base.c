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

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	includes(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	to_base(int nbr, char *base)
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
		to_base(nbr_long / base_len, base);
	ft_putchar(base[nbr_long % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
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
	to_base(nbr, base);
}
