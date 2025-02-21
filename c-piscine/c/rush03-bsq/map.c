/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:05:22 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/21 16:50:27 by fertorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

t_map	*read_meta_info(int file_descriptor)
{
	t_map	*map;
	char	line_buffer[5];

	map = malloc(sizeof(t_map));
	read(file_descriptor, line_buffer, 5);
	map->height = line_buffer[0] - '0';
	map->empty_char = line_buffer[1];
	map->block_char = line_buffer[2];
	map->full_char = line_buffer[3];
	map->map = malloc(map->height * sizeof(int *));
	return (map);
}

t_map	*read_body(int file_descriptor)
{
	int		i;
	int		line_len;
	char	line_buffer[9999];
	t_map	*map;

	map = read_meta_info(file_descriptor);
	i = 0;
	while (i < map->height)
	{
		line_len = calculate_line_len(file_descriptor);
		if (map->width != 0 && map->width != line_len)
			return (NULL);
		map->width = line_len;
		map->map[i] = malloc(map->width * sizeof(int));
		while (line_len > 0)
		{
			line_len--;
			map->map[i][line_len] = 1;
			if (line_buffer[line_len] == map->block_char)
				map->map[i][line_len] = 0;
		}
		i++;
	}
	return (map);
}

t_map	*read_map_from_file(char *file_name)
{
	int		file_descriptor;
	t_map	*map;

	file_descriptor = open(file_name, O_RDONLY);
	if (file_descriptor == -1)
		return (NULL);
	map = read_body(file_descriptor);
	close(file_descriptor);
	return (map);
}

void	calculate_max_side(t_map *map, t_solution *solution, int **dp)
{
	int	i;
	int	j;
	int	max_side;

	max_side = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] == 1)
			{
				max_side = dp[i + 1][j];
				dp[i + 1][j + 1] = min(dp[i][j], max_side, dp[i][j + 1]) + 1;
				max_side = max(solution->side, dp[i + 1][j + 1]);
				if (max_side > solution->side)
				{
					solution->x = i;
					solution->y = j;
					solution->side = max_side;
				}
			}
		}
	}
}

t_solution	*solve(t_map *map)
{
	int				rows;
	int				cols;
	int				**dp;
	t_solution		*solution;

	solution = malloc(sizeof(t_solution));
	if (!map->map || !map->height || !map->width)
	{
		solution->x = -1;
		solution->y = -1;
		solution->side = 0;
		return (solution);
	}
	rows = map->height;
	cols = map->width;
	dp = create_empty_map(rows + 1, cols + 1);
	calculate_max_side(map, solution, dp);
	return (solution);
}
