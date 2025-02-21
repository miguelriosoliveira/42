/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:51:48 by mguardia          #+#    #+#             */
/*   Updated: 2023/06/18 15:33:48 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLIB_H
# define FTLIB_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct solution
{
	int	x;
	int	y;
	int	side;
}	t_solution;

typedef struct map
{
	int		height;
	int		width;
	char	empty_char;
	char	block_char;
	char	full_char;
	int		**map;
}	t_map;

t_map		*read_map_from_file(char *file_name);
void		ft_putchar(char c);
void		print_map(t_map *map, t_solution *solution);
t_solution	*solve(t_map *map);

int			min(int v1, int v2, int v3);
int			max(int v1, int v2);
int			**create_empty_map(int rows, int cols);
int			calculate_line_len(int file_descriptor);

void		ft_putchar(char c);
void		print_map(t_map *map, t_solution *solution);

void		free_map(t_map *map);
void		free_solution(t_solution *solution);

#endif
