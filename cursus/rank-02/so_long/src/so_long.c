/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:06:40 by mrios-es          #+#    #+#             */
/*   Updated: 2024/09/27 09:17:24 by mrios-es         ###   ########.fr       */
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

int	load_map(t_vars *vars, char *filename)
{
	int		fd;
	int		line_number;
	int		err;
	int		i;
	char	*line;
	char	**map;

	err = get_map_dimensions(filename, vars);
	ft_printf("valid dimentions? %d\n", !err);
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
		if (ft_strchr(line, '\n'))
			line[ft_strlen(line) - 1] = '\0';
		map[line_number] = line;
		i = 0;
		while (i < vars->map.width)
		{
			if (map[line_number][i] == MAP_PLAYER)
			{
				vars->player.x = i;
				vars->player.y = line_number;
			}
			else if (map[line_number][i] == MAP_COLLECTIBLE)
				vars->map.collectable_count++;
			i++;
		}
		line_number++;
	}
	vars->map.content = map;
	err = validate_map_surrounded(vars);
	ft_printf("map surrounded? %d\n", !err);
	if (err)
	{
		ft_printf("Error\nMap not surrounded by walls! \"%s\"\n", filename);
		return (1);
	}
	err = validate_path(vars);
	ft_printf("valid path? %d\n", !err);
	if (err)
	{
		ft_printf("Error\nMap has no valid path! \"%s\"\n", filename);
		return (1);
	}
	return (0);
}

int	init(t_vars *vars, char *map_path)
{
	int		err;

	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (1);
	vars->map.width = 0;
	vars->map.height = 0;
	vars->map.collectable_count = 0;
	vars->player.n_steps = 0;
	err = load_map(vars, map_path);
	if (err)
		return (free(vars->mlx), 1);
	vars->win = mlx_new_window(
		vars->mlx,
		vars->map.width * TILE_SIZE,
		vars->map.height * TILE_SIZE,
		map_path
	);
	if (!vars->win)
		return (free(vars->mlx), 1);
	err = load_sprites(vars);
	if (err)
		return (free(vars->mlx), free(vars->win), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		err;
	char	*map_path;

	if (argc != 2)
	{
		ft_printf("Error\nBad list of arguments!\n$ ./so_long <mapfile.ber>\n");
		return (1);
	}
	map_path = argv[1];

	err = init(&vars, map_path);
	if (err)
		return (1);

	// vars.mlx = mlx_init();
	// if (!vars.mlx)
	// 	return (1);
	// err = load_map(&vars, map_path);
	// if (err)
	// 	return (free(vars.mlx), 1);
	// vars.win = mlx_new_window(
	// 	vars.mlx,
	// 	vars.map.width * TILE_SIZE,
	// 	vars.map.height * TILE_SIZE,
	// 	map_path
	// );
	// if (!vars.win)
	// 	return (free(vars.mlx), 1);
	// err = load_sprites(&vars);
	// if (err)
	// 	return (free(vars.mlx), free(vars.win), 1);

	mlx_hook(vars.win, KeyPress, KeyPressMask, &on_keypress, &vars);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, &on_destroy, &vars);
	render(&vars, &vars.sprites.player_right);
	mlx_loop(vars.mlx);
	return (0);
}
