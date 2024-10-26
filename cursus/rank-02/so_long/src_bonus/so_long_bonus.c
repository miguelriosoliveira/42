/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:06:40 by mrios-es          #+#    #+#             */
/*   Updated: 2024/10/15 21:33:19 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	read_map(t_vars *vars, char *filename)
{
	char	**map;
	char	*line;
	int		y;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	map = ft_calloc(vars->map.height + 1, sizeof(char *));
	if (!map)
		return (1);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strchr(line, '\n'))
			line[ft_strlen(line) - 1] = '\0';
		map[y] = line;
		y++;
		line = get_next_line(fd);
	}
	vars->map.content = map;
	close(fd);
	return (0);
}

int	read_player_position(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->map.height)
	{
		x = 0;
		while (x < vars->map.width)
		{
			if (vars->map.content[y][x] == MAP_PLAYER)
			{
				vars->player.x = x;
				vars->player.y = y;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	load_map(t_vars *vars, char *filename)
{
	if (validate_map_dimensions(vars, filename))
		return (ft_printf("Error\nInvalid map dimensions! \"%s\"\n", filename));
	if (read_map(vars, filename))
		return (ft_printf("Error\nFailed reading map! \"%s\"\n", filename));
	if (validate_game_elements(vars))
		return (free_matrix(vars->map.content, vars->map.height),
			ft_printf("Error\nInvalid game elements! \"%s\"\n", filename));
	if (read_player_position(vars))
		return (ft_printf("Error\nFailed reading player! \"%s\"\n", filename));
	if (validate_map_surrounded(vars))
		return (free_matrix(vars->map.content, vars->map.height),
			ft_printf("Error\nNot enclosed by walls! \"%s\"\n", filename));
	if (validate_path(vars))
		return (free_matrix(vars->map.content, vars->map.height),
			ft_printf("Error\nMap has no valid path! \"%s\"\n", filename));
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
	vars->map.collectible_count = 0;
	vars->player.n_steps = 0;
	vars->player.direction = DIR_RIGHT;
	err = load_map(vars, map_path);
	if (err)
		return (free(vars->mlx), ft_printf("Error\nFailed loading map!\n"));
	vars->win = mlx_new_window(vars->mlx, vars->map.width * TILE_SIZE,
			(vars->map.height + 1) * TILE_SIZE, map_path);
	if (!vars->win)
		return (free(vars->mlx), 1);
	err = load_sprites(vars);
	if (err)
		return (free_matrix(vars->map.content, vars->map.height),
			mlx_destroy_window(vars->mlx, vars->win),
			mlx_destroy_display(vars->mlx),
			free(vars->mlx), ft_printf("Error\nFailed loading sprites!\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	char	*map_path;
	char	*ext;

	if (argc != 2)
	{
		ft_printf("Error\nBad list of arguments!\n$ ./so_long <mapfile.ber>\n");
		return (1);
	}
	map_path = argv[1];
	ext = ft_strrchr(map_path, '.');
	if (!ext || ft_strncmp(ext, ".ber", ft_strlen(ext)) != 0)
	{
		ft_printf("Error\nInvalid map extension! \"%s\"\n", map_path);
		return (1);
	}
	if (init(&vars, map_path))
		return (1);
	render(&vars, &vars.sprites.player_closed);
	mlx_hook(vars.win, KeyPress, KeyPressMask, &on_keypress, &vars);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, &on_destroy, &vars);
	mlx_loop_hook(vars.mlx, &on_loop, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
