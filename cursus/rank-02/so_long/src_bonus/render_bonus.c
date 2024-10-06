/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:21:16 by mrios-es          #+#    #+#             */
/*   Updated: 2024/10/06 17:21:30 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	render_sprite(t_vars *vars, t_sprite *sprite, int x, int y)
{
	mlx_put_image_to_window(
		vars->mlx,
		vars->win,
		sprite->img,
		x * TILE_SIZE,
		y * TILE_SIZE
		);
}

static void	render_map(t_vars *vars)
{
	int		x;
	int		y;
	char	*line;

	y = 0;
	while (y < vars->map.height)
	{
		line = vars->map.content[y];
		x = 0;
		while (x < vars->map.width)
		{
			if (line[x] == MAP_WALL)
				render_sprite(vars, &vars->sprites.wall, x, y);
			if (line[x] == MAP_EXIT)
				render_sprite(vars, &vars->sprites.exit, x, y);
			if (line[x] == MAP_COLLECTIBLE)
				render_sprite(vars, &vars->sprites.collectible, x, y);
			x++;
		}
		y++;
	}
}

void	render(t_vars *vars, t_sprite *player_sprite)
{
	mlx_clear_window(vars->mlx, vars->win);
	render_map(vars);
	render_sprite(vars, player_sprite, vars->player.x, vars->player.y);
}
