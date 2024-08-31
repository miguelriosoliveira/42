/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:21:16 by mrios-es          #+#    #+#             */
/*   Updated: 2024/08/31 18:25:02 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map_part(t_vars *vars, t_sprite *sprite, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, sprite->img, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_wall(t_vars *vars, int x, int y)
{
	render_map_part(vars, &vars->map.sprites.wall, x, y);
}

void	render_collectable(t_vars *vars, int x, int y)
{
	render_map_part(vars, &vars->map.sprites.collectable, x, y);
}

void	render_exit(t_vars *vars, int x, int y)
{
	render_map_part(vars, &vars->map.sprites.exit, x, y);
}

void	render_map(t_vars *vars)
{
	// top
	render_wall(vars, 0, 0);
	render_wall(vars, 1, 0);
	render_wall(vars, 2, 0);
	render_wall(vars, 3, 0);
	render_wall(vars, 4, 0);
	render_wall(vars, 5, 0);

	// left
	render_wall(vars, 0, 1);
	render_wall(vars, 0, 2);
	render_wall(vars, 0, 3);
	render_wall(vars, 0, 4);

	// right
	render_wall(vars, 5, 1);
	render_wall(vars, 5, 2);
	render_wall(vars, 5, 3);
	render_wall(vars, 5, 4);

	// bottom
	render_wall(vars, 0, 5);
	render_wall(vars, 1, 5);
	render_wall(vars, 2, 5);
	render_wall(vars, 3, 5);
	render_wall(vars, 4, 5);
	render_wall(vars, 5, 5);
}

void	render_player(t_vars *vars, t_sprite *sprite)
{
	mlx_put_image_to_window(
		vars->mlx,
		vars->win,
		sprite->img,
		vars->player.x,
		vars->player.y
	);
}

void	render(t_vars *vars, t_sprite *player_sprite)
{
	mlx_clear_window(vars->mlx, vars->win);
	render_map(vars);
	render_player(vars, player_sprite);
}
