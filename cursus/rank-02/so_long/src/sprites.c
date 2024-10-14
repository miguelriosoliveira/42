/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:35:14 by mrios-es          #+#    #+#             */
/*   Updated: 2024/10/14 21:59:33 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	t_sprites	*sp;

	sp = &vars->sprites;
	return (
		check_file(SPRITE_PLAYER_UP)
		|| check_file(SPRITE_PLAYER_DOWN)
		|| check_file(SPRITE_PLAYER_LEFT)
		|| check_file(SPRITE_PLAYER_RIGHT)
		|| check_file(SPRITE_WALL)
		|| check_file(SPRITE_COLLECTIBLE)
		|| check_file(SPRITE_EXIT)
		|| load_sprite(vars->mlx, &sp->player_up, SPRITE_PLAYER_UP)
		|| load_sprite(vars->mlx, &sp->player_down, SPRITE_PLAYER_DOWN)
		|| load_sprite(vars->mlx, &sp->player_left, SPRITE_PLAYER_LEFT)
		|| load_sprite(vars->mlx, &sp->player_right, SPRITE_PLAYER_RIGHT)
		|| load_sprite(vars->mlx, &sp->wall, SPRITE_WALL)
		|| load_sprite(vars->mlx, &sp->collectible, SPRITE_COLLECTIBLE)
		|| load_sprite(vars->mlx, &sp->exit, SPRITE_EXIT)
	);
}

void	free_sprites(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->sprites.player_up.img);
	mlx_destroy_image(vars->mlx, vars->sprites.player_down.img);
	mlx_destroy_image(vars->mlx, vars->sprites.player_left.img);
	mlx_destroy_image(vars->mlx, vars->sprites.player_right.img);
	mlx_destroy_image(vars->mlx, vars->sprites.wall.img);
	mlx_destroy_image(vars->mlx, vars->sprites.collectible.img);
	mlx_destroy_image(vars->mlx, vars->sprites.exit.img);
}
