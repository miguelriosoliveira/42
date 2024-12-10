/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:05:11 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/13 19:05:11 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned int	base_len;
	int				char_count;

	base_len = ft_strlen(base);
	char_count = 0;
	if (nbr >= base_len)
		char_count += ft_putnbr_base(nbr / base_len, base);
	char_count += ft_putchar_fd(base[nbr % base_len], 1);
	if (char_count != count_base_len(nbr, base))
		char_count = -1;
	return (char_count);
}
