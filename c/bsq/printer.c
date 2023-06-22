/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:19:28 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/21 17:19:30 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_map(t_map *map, t_solution *solution)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 0)
				ft_putchar(map->block_char);
			else if (i > (solution->x - solution->side)
				&& i <= solution->x
				&& j > (solution->y - solution->side)
				&& j <= solution->y)
				ft_putchar(map->full_char);
			else
				ft_putchar(map->empty_char);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
