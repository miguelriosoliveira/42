/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:20:41 by mrios-es          #+#    #+#             */
/*   Updated: 2024/09/28 16:44:12 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_dimensions(t_vars *vars, char *filename)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)))
	{
		width = ft_strlen(line);
		if (ft_strchr(line, '\n'))
			width--;
		if (vars->map.width && vars->map.width != width)
			return (free(line), 1);
		vars->map.width = width;
		vars->map.height++;
		free(line);
	}
	close(fd);
	return (!vars->map.width || !vars->map.height);
}

int	validate_map_surrounded(t_vars *vars)
{
	int		i;
	int		last_index;
	char	**map;

	map = vars->map.content;
	last_index = vars->map.height - 1;
	i = 0;
	while (i < vars->map.width)
	{
		if (map[0][i] != MAP_WALL || map[last_index][i] != MAP_WALL)
			return (1);
		i++;
	}
	i = 0;
	last_index = vars->map.width - 1;
	while (i < vars->map.height)
	{
		if (map[i][0] != MAP_WALL || map[i][last_index] != MAP_WALL)
			return (1);
		i++;
	}
	return (0);
}

char	**clone_matrix(char **matrix, int width, int height)
{
	int		i;
	char	**clone;

	clone = ft_calloc(height + 1, sizeof(char *));
	i = 0;
	while (i < height)
	{
		clone[i] = ft_calloc(width + 1, sizeof(char));
		ft_strlcpy(clone[i], matrix[i], ft_strlen(matrix[i]) + 1);
		i++;
	}
	return (clone);
}

int	has_valid_path(char **map, int *collectible_count, int x, int y)
{
	int		found;
	char	c;

	c = map[y][x];
	if (c == MAP_WALL)
		return (0);
	if (c == MAP_COLLECTIBLE)
		*collectible_count -= 1;
	map[y][x] = MAP_WALL;
	found = 0;
	found += has_valid_path(map, collectible_count, x + 1, y    );
	found += has_valid_path(map, collectible_count, x - 1, y    );
	found += has_valid_path(map, collectible_count, x    , y - 1);
	found += has_valid_path(map, collectible_count, x    , y + 1);
	if (c == MAP_EXIT)
		return (*collectible_count == 0);
	return (found > 0);
}

int	validate_path(t_vars *vars)
{
	char	**map;
	int		collectible_count;
	int		is_path_valid;

	map = clone_matrix(vars->map.content, vars->map.width, vars->map.height);
	collectible_count = vars->map.collectible_count;
	is_path_valid = has_valid_path(
		map,
		&collectible_count,
		vars->player.x,
		vars->player.y
	);
	// TODO: free clone map
	return (!is_path_valid);
}
