/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:21:16 by mrios-es          #+#    #+#             */
/*   Updated: 2024/09/25 21:09:37 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map_part(t_vars *vars, t_sprite *sprite, int x, int y)
{
	mlx_put_image_to_window(
		vars->mlx,
		vars->win,
		sprite->img,
		x * TILE_SIZE,
		y * TILE_SIZE
	);
}

void	render_wall(t_vars *vars, int x, int y)
{
	render_map_part(vars, &vars->sprites.wall, x, y);
}

void	render_collectable(t_vars *vars, int x, int y)
{
	render_map_part(vars, &vars->sprites.collectable, x, y);
}

void	render_exit(t_vars *vars, int x, int y)
{
	render_map_part(vars, &vars->sprites.exit, x, y);
}

void	render_map(t_vars *vars)
{
	int		x;
	int		y;
	char	*line;

	y = 0;
	while (vars->map.content[y])
	{
		line = vars->map.content[y];
		x = 0;
		while (x < (int)ft_strlen(line))
		{
			if (line[x] == MAP_WALL)
				render_wall(vars, x, y);
			if (line[x] == MAP_COLLECTIBLE)
				render_collectable(vars, x, y);
			if (line[x] == MAP_EXIT)
				render_exit(vars, x, y);
			x++;
		}
		y++;
	}
}

void	render_player(t_vars *vars, t_sprite *sprite)
{
	mlx_put_image_to_window(
		vars->mlx,
		vars->win,
		sprite->img,
		vars->player.x * TILE_SIZE,
		vars->player.y * TILE_SIZE
	);
}

void	render(t_vars *vars, t_sprite *player_sprite)
{
	mlx_clear_window(vars->mlx, vars->win);
	render_map(vars);
	render_player(vars, player_sprite);
}
