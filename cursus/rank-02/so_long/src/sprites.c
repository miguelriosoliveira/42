/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:35:14 by mrios-es          #+#    #+#             */
/*   Updated: 2024/09/28 18:01:21 by mrios-es         ###   ########.fr       */
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
	if (!sprite->img)
		return (1);
	sprite->addr = mlx_get_data_addr(
			sprite->img,
			&sprite->bits_per_pixel,
			&sprite->line_length,
			&sprite->endian
			);
	return (0);
}

int	load_sprites(t_vars *vars)
{
	t_sprites	*sprites;

	sprites = &vars->sprites;
	return (
		load_sprite(vars->mlx, &sprites->player_down, SPRITE_PLAYER_DOWN)
		|| load_sprite(vars->mlx, &sprites->player_up, SPRITE_PLAYER_UP)
		|| load_sprite(vars->mlx, &sprites->player_left, SPRITE_PLAYER_LEFT)
		|| load_sprite(vars->mlx, &sprites->player_right, SPRITE_PLAYER_RIGHT)
		|| load_sprite(vars->mlx, &sprites->wall, SPRITE_WALL)
		|| load_sprite(vars->mlx, &sprites->collectible, SPRITE_COLLECTIBLE)
		|| load_sprite(vars->mlx, &sprites->exit, SPRITE_EXIT)
	);
}
