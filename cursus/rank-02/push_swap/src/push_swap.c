/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:33:01 by mrios-es          #+#    #+#             */
/*   Updated: 2024/12/24 14:01:37 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_numeric(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	validate_args(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (EXIT_SUCCESS);
	// TODO: validate non-numeric args
	i = 1;
	while (argv[i])
	{
		if (!is_numeric(argv[i]))
			return (EXIT_FAILURE);
		i++;
	}
	// TODO: validate numbers that don't fit into the int type
	// TODO: validate duplucates
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (validate_args(argc, argv))
		return (ft_printf("Error\n"));
	return (EXIT_SUCCESS);
}
