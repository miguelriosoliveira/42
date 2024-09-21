/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:20:41 by mrios-es          #+#    #+#             */
/*   Updated: 2024/09/21 21:21:45 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(char *filename, t_vars *vars)
{
	int		fd;
	int		i;
	int		exit_count;
	int		player_count;
	int		new_width;
	char	*line;
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strncmp(extension, ".ber", ft_strlen(extension)) != 0)
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	vars->map.width = 0;
	vars->map.height = 0;
	vars->map.collectable_count = 0;
	exit_count = 0;
	player_count = 0;
	vars->player.n_steps = 0;
	while ((line = get_next_line(fd)))
	{
		new_width = ft_strlen(line);
		if (ft_strchr(line, '\n'))
			line[new_width--] = '\0';
		if (vars->map.width && vars->map.width != new_width)
			return (1);
		vars->map.width = new_width;
		i = 0;
		while (i < vars->map.width)
		{
			if (line[i] == MAP_COLLECTABLE)
				vars->map.collectable_count++;
			else if (line[i] == MAP_PLAYER)
			{
				player_count++;
				vars->player.x = i;
				vars->player.y = vars->map.height;
			}
			else if (line[i] == MAP_EXIT)
				exit_count++;
			else if (line[i] != MAP_GROUND && line[i] != MAP_WALL)
				return (1);
			i++;
		}
		vars->map.height++;
	}
	close(fd);
	if (vars->map.collectable_count < 1 || exit_count != 1 || player_count != 1)
		return (1);
	return (0);
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

int	has_valid_path(t_vars *vars, char **map, int *collectable_count, int x1, int y1)
{
	int		found;
	char	c;

	c = map[y1][x1];
	if (c == MAP_WALL)
		return (0);
	if (c == MAP_COLLECTABLE)
		*collectable_count -= 1;
	map[y1][x1] = MAP_WALL;
	found = 0;
	found += has_valid_path(vars, map, collectable_count, x1 + 1, y1    );
	found += has_valid_path(vars, map, collectable_count, x1 - 1, y1    );
	found += has_valid_path(vars, map, collectable_count, x1    , y1 - 1);
	found += has_valid_path(vars, map, collectable_count, x1    , y1 + 1);
	if (c == MAP_EXIT)
		return (*collectable_count == 0);
	return (found > 0);
}

int	validate_path(t_vars *vars)
{
	char	**map;
	int		collectable_count;
	int		is_path_valid;

	map = clone_matrix(vars->map.content, vars->map.width, vars->map.height);
	collectable_count = vars->map.collectable_count;
	is_path_valid = has_valid_path(
		vars,
		map,
		&collectable_count,
		vars->player.x,
		vars->player.y
	);
	return (!is_path_valid);
}
