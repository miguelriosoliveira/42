/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:13:02 by mrios-es          #+#    #+#             */
/*   Updated: 2024/09/28 17:13:16 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map *map)
{
	int	i;

	ft_printf("-----------------------------\n");
	i = 0;
	while (i < map->height)
	{
		ft_printf("line %d: |%s|\n", i, map->content[i]);
		i++;
	}
}

void	print_map2(char **map)
{
	int	i;

	ft_printf("-----------------------------\n");
	i = 0;
	while (map[i])
	{
		ft_printf("line %d: |%s|\n", i, map[i]);
		i++;
	}
}

void	print_vars(t_vars *vars)
{
	ft_printf("map dimensions: (%d, %d)\n", vars->map.width, vars->map.height);
	print_map(&vars->map);
	ft_printf("collectibles count: %d\n", vars->map.collectible_count);
	ft_printf("player position: (%d, %d)\n", vars->player.x, vars->player.y);
}
