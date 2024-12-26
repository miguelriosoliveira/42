/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:56:54 by mrios-es          #+#    #+#             */
/*   Updated: 2024/12/26 10:57:37 by mrios-es         ###   ########.fr       */
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
	char	**args;
	int		i;
	long	number;

	if (argc < 2)
		return (EXIT_SUCCESS);
	args = argv + 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	i = 0;
	while (args[i])
	{
		if (!is_numeric(args[i]))
			return (EXIT_FAILURE);
		number = ft_atoi(args[i]);
		if (number < INT_MIN || number > INT_MAX)
			return (EXIT_FAILURE);
		if (is_present(args[i], args + i + 1))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
