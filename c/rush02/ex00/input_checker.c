/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:20:37 by mguardia          #+#    #+#             */
/*   Updated: 2023/06/17 21:00:17 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	input_checker(char *str)
{
	int	number;

	number = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		number *= 10;
		number += *str - 48;
		str++;
	}
	return (number);
}

/*
int	main(int argc, char **argv)
{
	char	*number;
	char	*dict_name;
	// Validacion del input
	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else if (argc == 2)
	{
		number = input_checker(argv[1]);
		dict_name = "numbers.dict";
	}
	else
	{
		number = input_checker(argv[2]);
		dict_name = argv[1];
	}
	// Verificar si existe el diccionario
	// Verificar si se puede leer el numero
	// Imprimirlo si existe
	return (0);
}
*/