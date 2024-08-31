/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:35:14 by mrios-es          #+#    #+#             */
/*   Updated: 2024/08/31 18:26:37 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	err = load_sprite(vars->mlx, &vars->player.down, SPRITE_PLAYER_DOWN);
	if (err)
		return (1);
	err = load_sprite(vars->mlx, &vars->player.up, SPRITE_PLAYER_UP);
	if (err)
		return (1);
	err = load_sprite(vars->mlx, &vars->player.left, SPRITE_PLAYER_LEFT);
	if (err)
		return (1);
	err = load_sprite(vars->mlx, &vars->player.right, SPRITE_PLAYER_RIGHT);
	if (err)
		return (1);
	err = load_sprite(vars->mlx, &vars->map.sprites.wall, SPRITE_WALL);
	if (err)
		return (1);
	err = load_sprite(vars->mlx, &vars->map.sprites.collectable, SPRITE_COLLECTABLE);
	if (err)
		return (1);
	err = load_sprite(vars->mlx, &vars->map.sprites.exit, SPRITE_EXIT);
	if (err)
		return (1);
	return (0);
}
