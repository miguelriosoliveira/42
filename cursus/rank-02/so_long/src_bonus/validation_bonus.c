/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:20:41 by mrios-es          #+#    #+#             */
/*   Updated: 2024/10/13 19:55:02 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	validate_map_dimensions(t_vars *vars, char *filename)
{
	int		fd;
	int		width;
	int		err;
	char	*line;

	err = 0,
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		width = ft_strlen(line);
		if (ft_strchr(line, '\n'))
			width--;
		err += (vars->map.width && vars->map.width != width);
		vars->map.width = width;
		vars->map.height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (err);
}

int	validate_game_elements(t_vars *vars)
{
	int		x;
	int		y;
	int		e_count;
	int		p_count;
	char	c;

	p_count = 0;
	e_count = 0;
	y = -1;
	while (++y < vars->map.height)
	{
		x = -1;
		while (++x < vars->map.width)
		{
			c = vars->map.content[y][x];
			vars->map.collectible_count += (c == MAP_COLLECTIBLE);
			e_count += (c == MAP_EXIT);
			p_count += (c == MAP_PLAYER);
			if (c != MAP_COLLECTIBLE && c != MAP_EXIT && c != MAP_PLAYER
				&& c != MAP_WALL && c != MAP_GROUND && c != MAP_ENEMY)
				return (1);
		}
	}
	return (vars->map.collectible_count < 1 || e_count != 1 || p_count != 1);
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

static int	has_valid_path(char **map, int *collectible_count, int x, int y)
{
	int		found;
	char	c;

	c = map[y][x];
	if (c == MAP_WALL || c == MAP_ENEMY)
		return (0);
	if (c == MAP_COLLECTIBLE)
		*collectible_count -= 1;
	map[y][x] = MAP_WALL;
	found = 0;
	found += has_valid_path(map, collectible_count, x + 1, y);
	found += has_valid_path(map, collectible_count, x - 1, y);
	found += has_valid_path(map, collectible_count, x, y - 1);
	found += has_valid_path(map, collectible_count, x, y + 1);
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
	free_matrix(map, vars->map.height);
	return (!is_path_valid);
}
