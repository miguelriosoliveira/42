/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:06:40 by mrios-es          #+#    #+#             */
/*   Updated: 2024/09/21 21:06:53 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map *map)
{
	int	i;

	ft_printf("-----------------------------\n");
	i = 0;
	while (i < map->height)
	{
		ft_printf("line %d: |%s|\n", i, map->content[i]);
		i++;
	}
}

void	print_map2(char **map)
{
	int	i;

	ft_printf("-----------------------------\n");
	i = 0;
	while (map[i])
	{
		ft_printf("line %d: |%s|\n", i, map[i]);
		i++;
	}
}

void	print_vars(t_vars *vars)
{
	ft_printf("map dimensions: (%d, %d)\n", vars->map.width, vars->map.height);
	print_map(&vars->map);
	ft_printf("collectables count: %d\n", vars->map.collectable_count);
	ft_printf("player position: (%d, %d)\n", vars->player.x, vars->player.y);
}

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

int	load_map(t_vars *vars, char *filename)
{
	int		fd;
	int		line_number;
	int		err;
	char	*line;
	char	**map;

	err = validate_map(filename, vars);
	if (err)
	{
		ft_printf("Error\nInvalid map! \"%s\"\n", filename);
		return (1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	line_number = 0;
	map = ft_calloc(vars->map.height + 1, sizeof(char *));
	if (!map)
		return (1);
	while ((line = get_next_line(fd)))
	{
		map[line_number] = ft_strtrim(line, "\n");
		line_number++;
	}
	vars->map.content = map;
	err = validate_map_surrounded(vars);
	if (err)
	{
		ft_printf("Error\nMap not surrounded by walls! \"%s\"\n", filename);
		return (1);
	}
	err = validate_path(vars);
	if (err)
	{
		ft_printf("Error\nMap has no valid path! \"%s\"\n", filename);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		err;
	char	*map_file;

	if (argc != 2)
	{
		ft_printf("Error\nBad list of arguments!\n>\t./so_long <mapfile.ber>\n");
		return (1);
	}
	map_file = argv[1];

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);

	err = load_map(&vars, map_file);
	if (err)
		return (free(vars.mlx), 1);
	vars.win = mlx_new_window(
		vars.mlx,
		TILE_SIZE * vars.map.width,
		TILE_SIZE * vars.map.height,
		map_file
	);
	if (!vars.win)
		return (free(vars.mlx), 1);

	// register key press hook
	mlx_hook(vars.win, KeyPress, KeyPressMask, &on_keypress, &vars);

	// register destroy hook
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, &on_destroy, &vars);

	// load player sprites
	err = load_sprites(&vars);
	if (err)
		return (free(vars.mlx), 1);

	render(&vars, &vars.sprites.player_right);

	// Loop over the MLX pointer
	mlx_loop(vars.mlx);
	return (0);
}
