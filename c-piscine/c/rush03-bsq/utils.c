/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:03:14 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/21 16:03:16 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

int	min(int v1, int v2, int v3)
{
	int	minimum;
	int	i;

	minimum = 2147483647;
	i = 0;
	if (v1 < minimum)
		minimum = v1;
	if (v2 < minimum)
		minimum = v2;
	if (v3 < minimum)
		minimum = v3;
	return (minimum);
}

int	max(int v1, int v2)
{
	int	maximum;
	int	i;

	maximum = -2147483648;
	i = 0;
	if (v1 > maximum)
		maximum = v1;
	if (v2 > maximum)
		maximum = v2;
	return (maximum);
}

int	**create_empty_map(int rows, int cols)
{
	int	**map;
	int	i;
	int	j;

	map = malloc(rows * sizeof(int *));
	i = 0;
	while (i < rows)
	{
		map[i] = malloc(cols * sizeof(int));
		j = 0;
		while (j < cols)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}

int	calculate_line_len(int file_descriptor)
{
	int		line_len;
	char	line_buffer[9999];
	char	buffer[1];

	line_len = 0;
	while (read(file_descriptor, buffer, 1) > 0 && buffer[0] != '\n')
	{
		line_buffer[line_len] = buffer[0];
		line_len++;
	}
	return (line_len);
}
