/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:03:12 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/05 18:03:15 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_hex_line(unsigned int size, unsigned int i, unsigned char *ptr)
{
	unsigned int	j;
	unsigned char	byte;

	j = 0;
	while (j < 16 && i + j < size)
	{
		if (j % 8 == 0)
			write(1, " ", 1);
		write(1, " ", 1);
		byte = ptr[i + j];
		if (byte)
		{
			write(1, &HEX_BASE[byte / 16], 1);
			write(1, &HEX_BASE[byte % 16], 1);
		}
		else
			write(1, "  ", 2);
		j++;
	}
	while (j < 16)
	{
		write(1, "   ", 3);
		j++;
	}
	write(1, "  |", 3);
}

void	print_chars(unsigned int size, unsigned int i, unsigned char *ptr)
{
	int				j;
	unsigned char	byte;

	j = 0;
	while (j < 16 && i + j < size)
	{
		byte = ptr[i + j];
		if (byte)
		{
			if (byte >= 32 && byte <= 126)
				write(1, &byte, 1);
			else
				write(1, ".", 1);
		}
		j++;
	}
	write(1, "|", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned int	i;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_hex_line(size, i, ptr);
		print_chars(size, i, ptr);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
