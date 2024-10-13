/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:35:14 by mrios-es          #+#    #+#             */
/*   Updated: 2024/10/13 16:35:44 by mrios-es         ###   ########.fr       */
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

int	load_sprites(t_vars *vars)
{
	t_sprites	*sprites;

	sprites = &vars->sprites;
	return (
		load_sprite(vars->mlx, &sprites->player_closed, SPRITE_PLAYER_CLOSED)
		|| load_sprite(vars->mlx, &sprites->player_open_up, SPRITE_PLAYER_OPEN_UP)
		|| load_sprite(vars->mlx, &sprites->player_semi_up, SPRITE_PLAYER_SEMI_UP)
		|| load_sprite(vars->mlx, &sprites->player_open_down, SPRITE_PLAYER_OPEN_DOWN)
		|| load_sprite(vars->mlx, &sprites->player_semi_down, SPRITE_PLAYER_SEMI_DOWN)
		|| load_sprite(vars->mlx, &sprites->player_open_left, SPRITE_PLAYER_OPEN_LEFT)
		|| load_sprite(vars->mlx, &sprites->player_semi_left, SPRITE_PLAYER_SEMI_LEFT)
		|| load_sprite(vars->mlx, &sprites->player_open_right, SPRITE_PLAYER_OPEN_RIGHT)
		|| load_sprite(vars->mlx, &sprites->player_semi_right, SPRITE_PLAYER_SEMI_RIGHT)
		|| load_sprite(vars->mlx, &sprites->wall, SPRITE_WALL)
		|| load_sprite(vars->mlx, &sprites->collectible, SPRITE_COLLECTIBLE)
		|| load_sprite(vars->mlx, &sprites->enemy, SPRITE_ENEMY)
		|| load_sprite(vars->mlx, &sprites->exit, SPRITE_EXIT)
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
