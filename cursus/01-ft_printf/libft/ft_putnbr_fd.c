/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:05:11 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/13 19:05:11 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long		nbr;
	int			is_negative;
	static int	char_count;

	nbr = n;
	is_negative = 0;
	char_count = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
		is_negative = 1;
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		char_count++;
	}
	ft_putchar_fd(nbr % 10 + '0', fd);
	return (char_count + is_negative + 1);
}
