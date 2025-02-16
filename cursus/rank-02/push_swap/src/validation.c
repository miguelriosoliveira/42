/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:56:54 by mrios-es          #+#    #+#             */
/*   Updated: 2025/02/16 20:22:39 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_numeric(char *str)
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

static int	is_present(char *str, char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		if (ft_atoi(str) == ft_atoi(words[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	validate_number(char **args, int i)
{
	long	number;

	if (!is_numeric(args[i]))
		return (EXIT_FAILURE);
	number = ft_atoi(args[i]);
	if (number < INT_MIN || number > INT_MAX)
		return (EXIT_FAILURE);
	if (is_present(args[i], args + i + 1))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	validate_args(int argc, char **argv)
{
	char	**args;
	int		i;
	int		should_split;
	int		err;

	err = 0;
	args = argv + 1;
	should_split = argc == 2;
	if (should_split)
		args = ft_split(argv[1], ' ');
	i = 0;
	while (args[i])
	{
		err += validate_number(args, i);
		i++;
	}
	if (should_split)
		free_str_array(args);
	return (err > 0);
}
