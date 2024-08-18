/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:06:40 by mrios-es          #+#    #+#             */
/*   Updated: 2024/08/18 18:14:22 by mrios-es         ###   ########.fr       */
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

void	move(t_vars *vars, int direction)
{
	t_sprite	*sprite;
	if (direction == DIR_UP)
	{
		vars->player.y -= 1;
		sprite = &vars->player.back;
	}
	if (direction == DIR_DOWN)
	{
		vars->player.y += 1;
		sprite = &vars->player.front;
	}
	if (direction == DIR_LEFT)
	{
		vars->player.x -= 1;
		sprite = &vars->player.left;
	}
	if (direction == DIR_RIGHT)
	{
		vars->player.x += 1;
		sprite = &vars->player.right;
	}
	mlx_put_image_to_window(
		vars->mlx,
		vars->win,
		sprite->img,
		vars->player.x,
		vars->player.y
	);
}

int on_keypress(int keycode, t_vars *vars)
{
	(void)vars;
	printf("Pressed key: %d\n", keycode);
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

	err = load_sprite(vars->mlx, &vars->player.front, PLAYER_FRONT_SPRITE);
	if (err)
		return (1);
	err = load_sprite(vars->mlx, &vars->player.back, PLAYER_BACK_SPRITE);
	if (err)
		return (1);
	err = load_sprite(vars->mlx, &vars->player.left, PLAYER_LEFT_SPRITE);
	if (err)
		return (1);
	err = load_sprite(vars->mlx, &vars->player.right, PLAYER_RIGHT_SPRITE);
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
	vars.win = mlx_new_window(vars.mlx, 800, 600, "so_long");
	if (!vars.win)
		return (free(vars.mlx), 1);

	// register key press hook
	mlx_hook(vars.win, KeyPress, KeyPressMask, &on_keypress, &vars);

	// register destroy hook
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, &on_destroy, &vars);

	// load player sprites
	vars.player.x = 0;
	vars.player.y = 0;
	err = load_sprites(&vars);
	if (err)
		return (free(vars.mlx), 1);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.player.front.img, 0, 0);

	// Loop over the MLX pointer
	mlx_loop(vars.mlx);
	return (0);
}
