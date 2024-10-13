/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:21:16 by mrios-es          #+#    #+#             */
/*   Updated: 2024/10/13 16:09:54 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_sprite(t_vars *vars, t_sprite *sprite, int x, int y)
{
	mlx_put_image_to_window(
		vars->mlx,
		vars->win,
		sprite->img,
		x * TILE_SIZE,
		(y + 1) * TILE_SIZE
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
			if (line[x] == MAP_ENEMY)
				render_sprite(vars, &vars->sprites.enemy, x, y);
			x++;
		}
		y++;
	}
}

static void	render_steps(t_vars *vars)
{
	char	*steps_str;
	char	*display_str;

	steps_str = ft_itoa(vars->player.n_steps);
	display_str = ft_strjoin("STEPS COUNTER: ", steps_str);
	mlx_string_put(
		vars->mlx,
		vars->win,
		0.65 * TILE_SIZE,
		0.65 * TILE_SIZE,
		0x00FF0000,
		display_str
		);
	free(steps_str);
	free(display_str);
}

void	render(t_vars *vars, t_sprite *player_sprite)
{
	mlx_clear_window(vars->mlx, vars->win);
	render_map(vars);
	render_sprite(vars, player_sprite, vars->player.x, vars->player.y);
	render_steps(vars);
}
