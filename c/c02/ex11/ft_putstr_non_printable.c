/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:33:05 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/05 16:33:10 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(unsigned char c) {
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hex_digits[c / 16]);
	ft_putchar(hex_digits[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			print_hex(str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
}

/*
int main(void) {
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	write(1, "\n", 1);

	// Caso de prueba 1: Cadena con caracteres no imprimibles
	ft_putstr_non_printable("Hello\tworld\n");
	write(1, "\n", 1);

	// Caso de prueba 2: Cadena sin caracteres no imprimibles
	ft_putstr_non_printable("42 is awesome!");
	write(1, "\n", 1);

	// Caso de prueba 3: Cadena vacía
	ft_putstr_non_printable("");
	write(1, "\n", 1);

	ft_putstr_non_printable("asdf\x7f\x1fhi\x01\xfflol");
	write(1, "\n", 1);

	return 0;
}
*/