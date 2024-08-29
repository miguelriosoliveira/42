/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:06:40 by mrios-es          #+#    #+#             */
/*   Updated: 2024/08/29 23:10:07 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_map(t_vars *vars, char *filename)
{
	int		fd;
	int		line_number;
	int		i;
	char	*line;

	(void)vars;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	line_number = 0;
	while ((line = get_next_line(fd)))
	{
		ft_printf("line: %s", line);
		i = 0;
		while (i < (int)ft_strlen(line))
		{
			if (line[i] == '1')
				render_wall(vars, i, line_number);
			if (line[i] == '0')
				render_floor(vars, i, line_number);
			// if (line[i] == 'C')
			// 	render_collectable(vars, i, line_number);
			// if (line[i] == 'E')
			// 	render_exit(vars, i, line_number);
			if (line[i] == 'P')
			{
				vars->player.x = TILE_SIZE * i;
				vars->player.y = TILE_SIZE * line_number;
				render_player(vars, &vars->player.front);
			}
			i++;
		}
		line_number++;
	}
	ft_printf("\nend of file %s\n", filename);
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
	vars.win = mlx_new_window(vars.mlx, TILE_SIZE * 20, TILE_SIZE * 10, "so_long");
	if (!vars.win)
		return (free(vars.mlx), 1);

	// register key press hook
	mlx_hook(vars.win, KeyPress, KeyPressMask, &on_keypress, &vars);

	// register destroy hook
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, &on_destroy, &vars);

	// load player sprites
	// vars.player.x = TILE_SIZE * 3;
	// vars.player.y = TILE_SIZE * 3;
	err = load_sprites(&vars);
	if (err)
		return (free(vars.mlx), 1);

	err = load_map(&vars, map_file);
	if (err)
		return (free(vars.mlx), 1);


	// render(&vars, &vars.player.front);

	// Loop over the MLX pointer
	mlx_loop(vars.mlx);
	return (0);
}
