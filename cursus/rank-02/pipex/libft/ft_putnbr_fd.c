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

int	ft_putnbr_fd(long n, int fd)
{
	int	n_written;
	int	char_count;

	n_written = 0;
	char_count = 0;
	if (n < 0)
	{
		n_written = ft_putchar_fd('-', fd);
		if (n_written == -1)
			return (-1);
		char_count += n_written;
		n = -n;
	}
	if (n >= 10)
	{
		n_written = ft_putnbr_fd(n / 10, fd);
		if (n_written == -1)
			return (-1);
		char_count += n_written;
	}
	n_written = ft_putchar_fd(n % 10 + '0', fd);
	if (n_written == -1)
		return (-1);
	char_count += n_written;
	return (char_count);
}
