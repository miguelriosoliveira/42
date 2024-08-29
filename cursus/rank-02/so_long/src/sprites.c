/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:35:14 by mrios-es          #+#    #+#             */
/*   Updated: 2024/08/22 21:59:34 by mrios-es         ###   ########.fr       */
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

	err = load_sprite(vars->mlx, &vars->floor, SPRITE_GROUND);
	if (err)
		return (1);
	err = load_sprite(vars->mlx, &vars->wall, SPRITE_WALL);
	if (err)
		return (1);

	return (0);
}
