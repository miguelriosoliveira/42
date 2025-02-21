/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:24:29 by mrios-es          #+#    #+#             */
/*   Updated: 2023/08/14 16:24:29 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	shift_left(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = '~';
}

void	fill(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		str[i] = '~';
		i++;
	}
	str[i] = '\0';
}

void	tail(char *filename, int bytes)
{
	int		file_descriptor;
	int		start;
	char	read_buffer;
	char	*write_buffer;

	file_descriptor = 0;
	if (filename)
	{
		file_descriptor = open(filename, O_RDONLY);
		start = calculate_start(filename, bytes);
		seek(file_descriptor, start);
	}
	write_buffer = malloc(bytes * sizeof(char));
	if (!write_buffer)
		return ;
	fill(write_buffer, bytes);
	while (read(file_descriptor, &read_buffer, sizeof(read_buffer)) > 0)
	{
		shift_left(write_buffer);
		write_buffer[bytes - 1] = read_buffer;
	}
	ft_putstr(write_buffer);
	if (filename)
		close(file_descriptor);
}

void	print_current_filename(char *filename)
{
	ft_putstr("==> ");
	ft_putstr(filename);
	ft_putstr(" <==\n");
}

void	ft_tail(int filecount, char **filenames, int bytes)
{
	char	*filename;
	int		i;

	if (filecount <= 1)
	{
		filename = filenames[0];
		if (filename && !check_file(filename))
			return ;
		tail(filename, bytes);
		return ;
	}
	i = 0;
	while (i < filecount)
	{
		filename = filenames[i];
		if (check_file(filename))
		{
			print_current_filename(filename);
			tail(filename, bytes);
			if (i < filecount - 1)
				ft_putstr("\n");
		}
		i++;
	}
}
