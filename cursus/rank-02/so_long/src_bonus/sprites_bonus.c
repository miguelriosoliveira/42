/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:35:14 by mrios-es          #+#    #+#             */
/*   Updated: 2024/10/17 20:01:07 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	load_sprite(void *mlx, t_sprite *sprite, char *sprite_file)
{
	sprite->img = mlx_xpm_file_to_image(
			mlx,
			sprite_file,
			&sprite->width,
			&sprite->height
			);
	return (!sprite->img);
}

static int	validate_sprites(void)
{
	return (
		check_file(SPRITE_PLAYER_CLOSED)
		|| check_file(SPRITE_PLAYER_OPEN_UP)
		|| check_file(SPRITE_PLAYER_SEMI_UP)
		|| check_file(SPRITE_PLAYER_OPEN_DOWN)
		|| check_file(SPRITE_PLAYER_SEMI_DOWN)
		|| check_file(SPRITE_PLAYER_OPEN_LEFT)
		|| check_file(SPRITE_PLAYER_SEMI_LEFT)
		|| check_file(SPRITE_PLAYER_OPEN_RIGHT)
		|| check_file(SPRITE_PLAYER_SEMI_RIGHT)
		|| check_file(SPRITE_WALL)
		|| check_file(SPRITE_COLLECTIBLE)
		|| check_file(SPRITE_ENEMY)
		|| check_file(SPRITE_EXIT)
	);
}

int	load_sprites(t_vars *vars)
{
	void		*mlx;
	t_sprites	*sp;

	mlx = vars->mlx;
	sp = &vars->sprites;
	return (
		validate_sprites()
		|| load_sprite(mlx, &sp->player_closed, SPRITE_PLAYER_CLOSED)
		|| load_sprite(mlx, &sp->player_open_up, SPRITE_PLAYER_OPEN_UP)
		|| load_sprite(mlx, &sp->player_semi_up, SPRITE_PLAYER_SEMI_UP)
		|| load_sprite(mlx, &sp->player_open_down, SPRITE_PLAYER_OPEN_DOWN)
		|| load_sprite(mlx, &sp->player_semi_down, SPRITE_PLAYER_SEMI_DOWN)
		|| load_sprite(mlx, &sp->player_open_left, SPRITE_PLAYER_OPEN_LEFT)
		|| load_sprite(mlx, &sp->player_semi_left, SPRITE_PLAYER_SEMI_LEFT)
		|| load_sprite(mlx, &sp->player_open_right, SPRITE_PLAYER_OPEN_RIGHT)
		|| load_sprite(mlx, &sp->player_semi_right, SPRITE_PLAYER_SEMI_RIGHT)
		|| load_sprite(mlx, &sp->wall, SPRITE_WALL)
		|| load_sprite(mlx, &sp->collectible, SPRITE_COLLECTIBLE)
		|| load_sprite(mlx, &sp->enemy, SPRITE_ENEMY)
		|| load_sprite(mlx, &sp->exit, SPRITE_EXIT)
	);
}

void	free_sprites(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->sprites.player_closed.img);
	mlx_destroy_image(vars->mlx, vars->sprites.player_open_up.img);
	mlx_destroy_image(vars->mlx, vars->sprites.player_semi_up.img);
	mlx_destroy_image(vars->mlx, vars->sprites.player_open_down.img);
	mlx_destroy_image(vars->mlx, vars->sprites.player_semi_down.img);
	mlx_destroy_image(vars->mlx, vars->sprites.player_open_left.img);
	mlx_destroy_image(vars->mlx, vars->sprites.player_semi_left.img);
	mlx_destroy_image(vars->mlx, vars->sprites.player_open_right.img);
	mlx_destroy_image(vars->mlx, vars->sprites.player_semi_right.img);
	mlx_destroy_image(vars->mlx, vars->sprites.wall.img);
	mlx_destroy_image(vars->mlx, vars->sprites.collectible.img);
	mlx_destroy_image(vars->mlx, vars->sprites.enemy.img);
	mlx_destroy_image(vars->mlx, vars->sprites.exit.img);
}

void	update_current_sprite(t_vars *vars, int tick)
{
	if (tick == 0)
		vars->sprites.player_current = &vars->sprites.player_closed;
	if (tick == 1 || tick == 3)
	{
		if (vars->player.direction == DIR_UP)
			vars->sprites.player_current = &vars->sprites.player_semi_up;
		if (vars->player.direction == DIR_DOWN)
			vars->sprites.player_current = &vars->sprites.player_semi_down;
		if (vars->player.direction == DIR_LEFT)
			vars->sprites.player_current = &vars->sprites.player_semi_left;
		if (vars->player.direction == DIR_RIGHT)
			vars->sprites.player_current = &vars->sprites.player_semi_right;
	}
	if (tick == 2)
	{
		if (vars->player.direction == DIR_UP)
			vars->sprites.player_current = &vars->sprites.player_open_up;
		if (vars->player.direction == DIR_DOWN)
			vars->sprites.player_current = &vars->sprites.player_open_down;
		if (vars->player.direction == DIR_LEFT)
			vars->sprites.player_current = &vars->sprites.player_open_left;
		if (vars->player.direction == DIR_RIGHT)
			vars->sprites.player_current = &vars->sprites.player_open_right;
	}
}
