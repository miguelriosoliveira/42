/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:50:32 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/18 16:14:00 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

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

int	get_num_quantity(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	return (count);
}

int	get_num_len(char *str, int i)
{
	int	count;

	count = 0;
	while (str[i + count] && str[i + count] != '-')
		count++;
	return (count);
}

void	translate(char *numbers_str, char *dict_name)
{
	int		num_len;
	int		i;
	int		j;
	char	*num_str;

	num_len = 0;
	i = 0;
	j = 0;
	while (i < ft_strlen(numbers_str))
	{
		num_len = get_num_len(numbers_str, i);
		num_str = malloc((num_len + 1) * sizeof(char));
		j = 0;
		while (j < num_len)
		{
			num_str[j] = numbers_str[i + j];
			j++;
		}
		num_str[j] = '\0';
		get_number_name(num_str, dict_name);
		ft_putchar(' ');
		free(num_str);
		i += num_len + 1;
	}
}

int	main(int argc, char **argv)
{
	int		number;
	char	*dict_name;
	char	*numbers_str;
	int		total_char;

	dict_name = "numbers.dict";
	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else if (argc == 2)
		number = input_checker(argv[1]);
	else
	{
		number = input_checker(argv[2]);
		dict_name = argv[1];
	}
	total_char = 0;
	count_num_chars(number, 1, &total_char);
	numbers_str = malloc((total_char + 1) * sizeof(char));
	fill_num_chars(number, 1, numbers_str);
	translate(numbers_str, dict_name);
	free(numbers_str);
	return (0);
}
