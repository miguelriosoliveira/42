/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:19:57 by mrios-es          #+#    #+#             */
/*   Updated: 2023/08/17 22:19:57 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_file(char *filename)
{
	int		file_descriptor;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
	{
		ft_putstr_error("ft_tail: ");
		ft_putstr_error(filename);
		ft_putstr_error(": ");
		ft_putstr_error(strerror(errno));
		ft_putstr_error("\n");
		return (0);
	}
	close(file_descriptor);
	return (1);
}

int	count_chars(char *filename)
{
	int		file_descriptor;
	int		char_count;
	int		bytes_read;
	char	buffer[BLOCK_SIZE];

	file_descriptor = 0;
	char_count = 0;
	bytes_read = 1;
	if (filename)
		file_descriptor = open(filename, O_RDONLY);
	while (bytes_read > 0)
	{
		bytes_read = read(file_descriptor, buffer, sizeof(buffer));
		char_count += bytes_read;
	}
	if (filename)
		close(file_descriptor);
	return (char_count);
}

int	calculate_start(char *filename, int reverse_start)
{
	int		start;
	int		total_chars;

	total_chars = count_chars(filename);
	start = total_chars - reverse_start;
	if (start < 0)
		return (0);
	return (start);
}

void	seek(int file_descriptor, int position)
{
	int		blocks_to_read;
	char	buffer[BLOCK_SIZE];

	blocks_to_read = position / BLOCK_SIZE;
	while (blocks_to_read--)
		position -= read(file_descriptor, buffer, sizeof(buffer));
	read(file_descriptor, buffer, position);
}
