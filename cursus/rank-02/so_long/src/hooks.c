/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:23:10 by mrios-es          #+#    #+#             */
/*   Updated: 2024/09/07 23:03:10 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_vars *vars, int direction)
{
	t_sprite	*sprite;
	int			x;
	int			y;

	x = vars->player.x;
	y = vars->player.y;
	if (direction == DIR_UP)
	{
		sprite = &vars->sprites.player_up;
		if (vars->map.content[y - 1][x] != MAP_WALL)
			vars->player.y--;
	}
	if (direction == DIR_DOWN)
	{
		sprite = &vars->sprites.player_down;
		if (vars->map.content[y + 1][x] != MAP_WALL)
			vars->player.y++;
	}
	if (direction == DIR_LEFT)
	{
		sprite = &vars->sprites.player_left;
		if (vars->map.content[y][x - 1] != MAP_WALL)
			vars->player.x--;
	}
	if (direction == DIR_RIGHT)
	{
		sprite = &vars->sprites.player_right;
		if (vars->map.content[y][x + 1] != MAP_WALL)
			vars->player.x++;
	}
	if (vars->player.x != x || vars->player.y != y)
	{
		vars->player.n_steps++;
		ft_printf("steps count: %d\n", vars->player.n_steps);
	}
	x = vars->player.x;
	y = vars->player.y;
	if (vars->map.content[y][x] == MAP_COLLECTABLE)
	{
		vars->map.content[y][x] = MAP_GROUND;
		vars->map.collectable_count--;
	}
	if (vars->map.content[y][x] == MAP_EXIT && vars->map.collectable_count == 0)
	{
		ft_printf("YOU WIN!\n");
		on_destroy(vars);
	}
	// print_vars(vars);
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
