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

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_address(char *c)
{
	long	address;
	char	*hex_digits;

	address = (long)c;
	hex_digits = "0123456789abcdef";
	while (address > 0)
	{
		ft_putchar(hex_digits[address % 16]);
		address /= 16;
	}
	ft_putchar(':');
}

void	print_hex_line(char *str, unsigned int start)
{
	unsigned int	j;
	char			*hex_digits;

	j = start;
	hex_digits = "0123456789abcdef";
	while (j < start + 15)
	{
		if (str[j])
		{
			ft_putchar(hex_digits[str[j] / 16]);
			ft_putchar(hex_digits[str[j] % 16]);
			ft_putchar(hex_digits[str[j + 1] / 16]);
			ft_putchar(hex_digits[str[j + 1] % 16]);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
			ft_putchar(' ');
			ft_putchar(' ');
		}
		ft_putchar(' ');
		j += 2;
	}
}

void	print_line(char *str, unsigned int start)
{
	unsigned int	j;

	j = start;
	while (j < start + 16 && str[j])
	{
		if (str[j] < 32 || str[j] > 126)
			ft_putchar('.');
		else
			ft_putchar(str[j]);
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			*str;
	unsigned int	i;

	if (size == 0)
		return ("");
	str = addr;
	i = 0;
	while (i < size - 16)
	{
		print_address(&str[i]);
		ft_putchar(' ');
		print_hex_line(str, i);
		print_line(str, i);
		ft_putchar('\n');
		i += 16;
	}
	print_address(&str[i]);
	ft_putchar(' ');
	print_hex_line(str, i);
	print_line(str, i);
	ft_putchar('.');
	ft_putchar('\n');
	return (addr);
}

/*
#include <string.h>

int main() {
	char addr1[93] = "Bonjour les aminches...c. est fou.tout.ce qu on peut faire";
	strcat(addr1, " avec...print_memory....lol.lol. .");
	ft_print_memory(addr1, strlen(addr1));

	ft_putchar('\n');

	char addr2[107] = "Bonjour les aminches\t\n\tc\07 est fou\ttout\tce qu on pe";
	strcat(addr2, "ut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ");
	ft_print_memory(addr2, strlen(addr2));

	ft_putchar('\n');

	char *addr3 = "Bonjour les aminches";
	ft_print_memory(addr3, 0);

	return 0;
}
*/