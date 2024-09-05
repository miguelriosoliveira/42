/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:06:40 by mrios-es          #+#    #+#             */
/*   Updated: 2024/09/06 00:15:09 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_line(void *line)
{
	ft_printf("line: (%s)", line);
}

void	validate_map(char *filename, t_dimensions *dimensions)
{
	int		fd;
	int		line_number;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return;
	line_number = 0;

	while ((line = get_next_line(fd)))
	{
		dimensions->width = ft_strlen(line);
		line_number++;
	}
	dimensions->height = line_number;
	close(fd);
}

int	load_map(t_vars *vars, char *filename)
{
	int		fd;
	int		line_number;
	int		i;
	char	*line;
	char	**map;

	t_dimensions	*dimensions;
	dimensions = &vars->map.dimensions;
	validate_map(filename, dimensions);

	(void)vars;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	line_number = 0;
	map = ft_calloc(dimensions->height + 1, sizeof(char *));
	while ((line = get_next_line(fd)))
	{
		ft_printf("line %d: %s", line_number, line);
		map[line_number] = line;
		i = 0;
		while (i < (int)ft_strlen(line))
		{
			if (line[i] == MAP_PLAYER)
			{
				vars->player.x = TILE_SIZE * i;
				vars->player.y = TILE_SIZE * line_number;
			}
			i++;
		}
		line_number++;
	}
	ft_printf("\nend of file %s\n", filename);

	vars->map.content = map;

	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		err;
	char	*map_file;

	if (argc != 2)
	{
		ft_printf("Bad list of arguments!\n>\t./so_long <mapfile.ber>\n");
		return (1);
	}
	map_file = argv[1];

	ft_printf("map_file: \"%s\"\n", map_file);

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);

	err = load_map(&vars, map_file);
	if (err)
		return (free(vars.mlx), 1);

	vars.win = mlx_new_window(
		vars.mlx,
		TILE_SIZE * vars.map.dimensions.width,
		TILE_SIZE * vars.map.dimensions.height,
		"so_long"
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

	render(&vars, &vars.player.right);

	// Loop over the MLX pointer
	mlx_loop(vars.mlx);
	return (0);
}
