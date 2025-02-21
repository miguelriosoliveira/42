/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:46:33 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/21 16:29:21 by fertorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

int	input_check(int argc)
{
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_map		*map;
	t_solution	*solution;
	int			i;

	if (!input_check(argc))
		return (1);
	i = 1;
	while (i < argc)
	{
		map = read_map_from_file(argv[i]);
		if (map)
		{
			solution = solve(map);
			print_map(map, solution);
		}
		else
			write(1, "map error\n", 10);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	free_map(map);
	free_solution(solution);
	return (0);
}
