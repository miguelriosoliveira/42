/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:33:01 by mrios-es          #+#    #+#             */
/*   Updated: 2024/12/24 15:09:03 by mrios-es         ###   ########.fr       */
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

int	is_present(char *str, char **words)
{
	int	i;
	int	largest_len;

	i = 0;
	while (words[i])
	{
		largest_len = max(ft_strlen(str), ft_strlen(words[i]));
		if (ft_strncmp(str, words[i], largest_len) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	validate_args(int argc, char **argv)
{
	int		i;
	long	number;

	if (argc < 2)
		return (EXIT_SUCCESS);
	i = 1;
	while (argv[i])
	{
		if (!is_numeric(argv[i]))
			return (EXIT_FAILURE);
		number = ft_atoi(argv[i]);
		if (number < INT_MIN || number > INT_MAX)
			return (EXIT_FAILURE);
		if (is_present(argv[i], argv + i + 1))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (validate_args(argc, argv))
		return (ft_printf("Error\n"));
	return (EXIT_SUCCESS);
}
