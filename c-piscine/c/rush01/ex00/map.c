/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 21:28:43 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/11 21:28:45 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define SIZE 4

int	**create_map(void)
{
	int	i;
	int	j;
	int	**map;

	i = 0;
	map = malloc(SIZE * sizeof(int *));
	while (i < SIZE)
	{
		map[i] = malloc(SIZE * sizeof(int));
		i++;
	}
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}

void	free_map(int **map)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
