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

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
		{
			ft_putchar('\\');
			ft_putchar(hex_digits[str[i] / 16]);
			ft_putchar(hex_digits[str[i] % 16]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

/*
#include <stdio.h>

int main(void) {
	char str[] = "Coucou\ntu vas bien ?";
  ft_putstr_non_printable(str);
	write(1, "\n", 1);

	// Caso de prueba 1: Cadena con caracteres no imprimibles
	char str1[] = "Hello\tworld\n";
	ft_putstr_non_printable(str1);
	write(1, "\n", 1);

	// Caso de prueba 2: Cadena sin caracteres no imprimibles
	char str2[] = "42 is awesome!";
	ft_putstr_non_printable(str2);
	write(1, "\n", 1);

	// Caso de prueba 3: Cadena vacía
	char str3[] = "";
	ft_putstr_non_printable(str3);
	write(1, "\n", 1);

	return 0;
}
*/
