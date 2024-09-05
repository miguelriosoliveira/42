/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:23:10 by mrios-es          #+#    #+#             */
/*   Updated: 2024/09/06 00:16:10 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_vars *vars, int direction)
{
	t_sprite	*sprite;
	int			pace;
	int			x;
	int			y;

	pace = TILE_SIZE;
	x = vars->player.x / pace;
	y = vars->player.y / pace;
	if (direction == DIR_UP)
	{
		sprite = &vars->player.up;
		if (vars->map.content[y - 1][x] != MAP_WALL)
			vars->player.y -= pace;
	}
	if (direction == DIR_DOWN)
	{
		sprite = &vars->player.down;
		if (vars->map.content[y + 1][x] != MAP_WALL)
			vars->player.y += pace;
	}
	if (direction == DIR_LEFT)
	{
		sprite = &vars->player.left;
		if (vars->map.content[y][x - 1] != MAP_WALL)
			vars->player.x -= pace;
	}
	if (direction == DIR_RIGHT)
	{
		sprite = &vars->player.right;
		if (vars->map.content[y][x + 1] != MAP_WALL)
			vars->player.x += pace;
	}
	render(vars, sprite);
}

int on_keypress(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		on_destroy(vars);
	else if (keycode == W || keycode == ARROW_UP)
		move(vars, DIR_UP);
	else if (keycode == A || keycode == ARROW_LEFT)
		move(vars, DIR_LEFT);
	else if (keycode == S || keycode == ARROW_DOWN)
		move(vars, DIR_DOWN);
	else if (keycode == D || keycode == ARROW_RIGHT)
		move(vars, DIR_RIGHT);
	return (0);
}

int on_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}
