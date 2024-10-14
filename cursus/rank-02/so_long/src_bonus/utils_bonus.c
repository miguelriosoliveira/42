/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:02:20 by mrios-es          #+#    #+#             */
/*   Updated: 2024/10/14 21:59:02 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_file(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

char	**clone_matrix(char **matrix, int width, int height)
{
	int		i;
	char	**clone;

	clone = ft_calloc(height + 1, sizeof(char *));
	i = 0;
	while (i < height)
	{
		clone[i] = ft_calloc(width + 1, sizeof(char));
		ft_strlcpy(clone[i], matrix[i], ft_strlen(matrix[i]) + 1);
		i++;
	}
	return (clone);
}

void	free_matrix(char **matrix, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
