/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:06:40 by mrios-es          #+#    #+#             */
/*   Updated: 2024/08/21 21:14:07 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

int on_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

void	render_map_part(t_vars *vars, t_sprite *sprite, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, sprite->img, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_floor(t_vars *vars, int x, int y)
{
	render_map_part(vars, &vars->floor, x, y);
}

void	render_wall(t_vars *vars, int x, int y)
{
	render_map_part(vars, &vars->wall, x, y);
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

	// floors in the middle
	render_floor(vars, 1, 1);
	render_floor(vars, 1, 2);
	render_floor(vars, 1, 3);
	render_floor(vars, 1, 4);
	render_floor(vars, 2, 1);
	render_floor(vars, 2, 2);
	render_floor(vars, 2, 3);
	render_floor(vars, 2, 4);
	render_floor(vars, 3, 1);
	render_floor(vars, 3, 2);
	render_floor(vars, 3, 3);
	render_floor(vars, 3, 4);
	render_floor(vars, 4, 1);
	render_floor(vars, 4, 2);
	render_floor(vars, 4, 3);
	render_floor(vars, 4, 4);

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

void	move(t_vars *vars, int direction)
{
	t_sprite	*sprite;
	int			pace;

	pace = vars->player.front.width;
	if (direction == DIR_UP)
	{
		vars->player.y -= pace;
		sprite = &vars->player.back;
	}
	if (direction == DIR_DOWN)
	{
		vars->player.y += pace;
		sprite = &vars->player.front;
	}
	if (direction == DIR_LEFT)
	{
		vars->player.x -= pace;
		sprite = &vars->player.left;
	}
	if (direction == DIR_RIGHT)
	{
		vars->player.x += pace;
		sprite = &vars->player.right;
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

int	load_sprite(void *mlx, t_sprite *sprite_part, char *sprite_file)
{
	sprite_part->img = mlx_xpm_file_to_image(
		mlx,
		sprite_file,
		&sprite_part->width,
		&sprite_part->height
	);
	if (!sprite_part->img)
		return (1);
	sprite_part->addr = mlx_get_data_addr(
		sprite_part->img,
		&sprite_part->bits_per_pixel,
		&sprite_part->line_length,
		&sprite_part->endian
	);
	return (0);
}

int	load_sprites(t_vars *vars)
{
	int	err;

	err = load_sprite(vars->mlx, &vars->player.front, SPRITE_PLAYER_FRONT);
	if (err)
		return (1);
	err = load_sprite(vars->mlx, &vars->player.back, SPRITE_PLAYER_BACK);
	if (err)
		return (1);
	err = load_sprite(vars->mlx, &vars->player.left, SPRITE_PLAYER_LEFT);
	if (err)
		return (1);
	err = load_sprite(vars->mlx, &vars->player.right, SPRITE_PLAYER_RIGHT);
	if (err)
		return (1);

	err = load_sprite(vars->mlx, &vars->floor, SPRITE_FLOOR);
	if (err)
		return (1);
	err = load_sprite(vars->mlx, &vars->wall, SPRITE_WALL);
	if (err)
		return (1);

	return (0);
}

int	main(void)
{
	t_vars	vars;
	int		err;

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
	vars.player.x = TILE_SIZE * 3;
	vars.player.y = TILE_SIZE * 3;
	err = load_sprites(&vars);
	if (err)
		return (free(vars.mlx), 1);
	render(&vars, &vars.player.front);

	// Loop over the MLX pointer
	mlx_loop(vars.mlx);
	return (0);
}
