/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:06:40 by mrios-es          #+#    #+#             */
/*   Updated: 2024/09/27 23:15:12 by mrios-es         ###   ########.fr       */
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

int	validate_map_extension(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	return (!ext || ft_strncmp(ext, ".ber", ft_strlen(ext)) != 0);
}

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
	while ((line = get_next_line(fd)))
	{
		if (ft_strchr(line, '\n'))
			line[ft_strlen(line) - 1] = '\0';
		map[y] = line;
		y++;
	}
	vars->map.content = map;
	close(fd);
	return (0);
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
	y = 0;
	while (y < vars->map.height)
	{
		x = 0;
		while (x < vars->map.width)
		{
			c = vars->map.content[y][x];
			vars->map.collectable_count += (c == MAP_COLLECTIBLE);
			e_count += (c == MAP_EXIT);
			p_count += (c == MAP_PLAYER);
			if (c != MAP_COLLECTIBLE && c != MAP_EXIT && c != MAP_PLAYER && c != MAP_WALL && c != MAP_GROUND)
				return (1);
			x++;
		}
		y++;
	}
	return (vars->map.collectable_count < 1 || e_count != 1 || p_count != 1);
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
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	load_map(t_vars *vars, char *filename)
{
	if (validate_map_extension(filename))
		return (ft_printf("Error\nInvalid map extension! \"%s\"\n", filename));
	if (validate_map_dimensions(vars, filename))
		return (ft_printf("Error\nInvalid map dimensions! \"%s\"\n", filename));
	if (read_map(vars, filename))
		return (ft_printf("Error\nFailed reading map! \"%s\"\n", filename));
	if (validate_game_elements(vars))
		return (ft_printf("Error\nInvalid game elements! \"%s\"\n", filename));
	if (read_player_position(vars))
		return (ft_printf("Error\nFailed reading player! \"%s\"\n", filename));
	if (validate_map_surrounded(vars))
		return (ft_printf("Error\nNot enclosed by walls! \"%s\"\n", filename));
	if (validate_path(vars))
		return (ft_printf("Error\nMap has no valid path! \"%s\"\n", filename));
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
	mlx_hook(vars.win, KeyPress, KeyPressMask, &on_keypress, &vars);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, &on_destroy, &vars);
	render(&vars, &vars.sprites.player_right);
	mlx_loop(vars.mlx);
	return (0);
}
