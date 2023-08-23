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
	char			*hex;
	unsigned int	j;
	unsigned char	byte;

	hex = "0123456789abcdef";
	j = 0;
	while (j < 16 && i + j < size)
	{
		if (j % 8 == 0)
			write(1, " ", 1);
		write(1, " ", 1);
		byte = ptr[i + j];
		if (byte)
		{
			write(1, &hex[byte / 16], 1);
			write(1, &hex[byte % 16], 1);
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

/*
#include <stdio.h>
#include <string.h>

int main() {
	char addr1[107] = "Bonjour les aminches\t\n\tc\07 est fou\ttout\tce qu on pe";
	strcat(addr1, "ut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ");
	ft_print_memory(addr1, strlen(addr1));
	printf("\n");

	char addr2[107] = "Bonjour les aminches\t\n\tc\07 est fou\ttout\tce qu on pe";
	strcat(addr2, "ut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ");
	ft_print_memory(addr2, 3);
	printf("\n");

	return 0;
}
*/
