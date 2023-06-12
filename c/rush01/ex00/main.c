/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:43:56 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/10 13:44:00 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SIZE 4

int		**create_map(void);
void	free_map(int **map);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_map(int **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		ft_putchar(map[i][1] + '0');
		j = 1;
		while (j < SIZE)
		{
			ft_putchar(' ');
			ft_putchar(map[i][j] + '0');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	parse_input(char *raw_hints, int *hints)
{
	int	i;
	int	j;

	i = 0;
	while (raw_hints[i])
	{
		if (raw_hints[i] == ' ')
		{
			j = i;
			while (raw_hints[j])
			{
				raw_hints[j] = raw_hints[j + 1];
				j++;
			}
		}
		i++;
	}
	i = 0;
	while (raw_hints[i])
	{
		hints[i] = raw_hints[i] - '0';
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// int	solve_puzzle()
// {
// }

int	main(int argc, char **argv)
{
	char	*input;
	int		hints[SIZE * SIZE];
	int		**map;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	input = argv[1];
	if (ft_strlen(input) != SIZE * SIZE * 2 - 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	parse_input(input, hints);
	map = create_map();
	print_map(map);
	free_map(map);
	return (0);
}
