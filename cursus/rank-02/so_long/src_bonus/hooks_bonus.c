/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:23:10 by mrios-es          #+#    #+#             */
/*   Updated: 2024/10/13 17:27:24 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	try_move(t_vars *vars)
{
	if (vars->player.direction == DIR_UP)
	{
		vars->sprites.player_current = &vars->sprites.player_semi_up;
		if (vars->map.content[vars->player.y - 1][vars->player.x] != MAP_WALL)
			vars->player.y--;
	}
	if (vars->player.direction == DIR_DOWN)
	{
		vars->sprites.player_current = &vars->sprites.player_semi_down;
		if (vars->map.content[vars->player.y + 1][vars->player.x] != MAP_WALL)
			vars->player.y++;
	}
	if (vars->player.direction == DIR_LEFT)
	{
		vars->sprites.player_current = &vars->sprites.player_semi_left;
		if (vars->map.content[vars->player.y][vars->player.x - 1] != MAP_WALL)
			vars->player.x--;
	}
	if (vars->player.direction == DIR_RIGHT)
	{
		vars->sprites.player_current = &vars->sprites.player_semi_right;
		if (vars->map.content[vars->player.y][vars->player.x + 1] != MAP_WALL)
			vars->player.x++;
	}
}

static void	move(t_vars *vars, int direction)
{
	int		x;
	int		y;
	char	pos;

	x = vars->player.x;
	y = vars->player.y;
	vars->player.direction = direction;
	try_move(vars);
	if (vars->player.x != x || vars->player.y != y)
		vars->player.n_steps++;
	render(vars, vars->sprites.player_current);
	pos = vars->map.content[vars->player.y][vars->player.x];
	if (pos == MAP_COLLECTIBLE)
	{
		vars->map.content[vars->player.y][vars->player.x] = MAP_GROUND;
		vars->map.collectible_count--;
	}
	if (pos == MAP_ENEMY || (pos == MAP_EXIT && !vars->map.collectible_count))
	{
		if (pos == MAP_ENEMY)
			ft_printf("YOU DIED!\nSteps taken: %d\n", vars->player.n_steps);
		else
			ft_printf("YOU WIN!\nSteps taken: %d\n", vars->player.n_steps);
		on_destroy(vars);
	}
}

int	on_keypress(int keycode, t_vars *vars)
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

int	on_destroy(t_vars *vars)
{
	free_sprites(vars);
	free_matrix(vars->map.content, vars->map.height);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

int	on_loop(t_vars *vars)
{
	static int	i;
	int			tick;

	tick = (i / CLOCK) % 4;
	update_current_sprite(vars, tick);
	render_sprite(
		vars,
		vars->sprites.player_current,
		vars->player.x,
		vars->player.y
		);
	i++;
	return (0);
}
