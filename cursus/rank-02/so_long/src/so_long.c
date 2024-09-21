/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:06:40 by mrios-es          #+#    #+#             */
/*   Updated: 2024/09/21 21:21:52 by mrios-es         ###   ########.fr       */
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
