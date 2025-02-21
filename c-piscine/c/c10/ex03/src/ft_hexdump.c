/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:26:03 by mrios-es          #+#    #+#             */
/*   Updated: 2023/08/18 18:26:03 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	print_offset(int offset)
{
	ft_putnbr_base(offset, "0123456789abcdef", 8);
}

void	hexdump(int *filecount, char ***filenames, int *file_descriptor)
{
	int		bytes_read;
	int		bytes_offset;
	char	buffer[LINE_SIZE];

	bytes_offset = 0;
	bytes_read = read(*file_descriptor, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		if (bytes_read < LINE_SIZE && *filecount > 0)
		{
			*filecount -= 1;
			*filenames += 1;
			close(*file_descriptor);
			*file_descriptor = open(**filenames, O_RDONLY);
			bytes_read += read(*file_descriptor,
					&buffer[bytes_read], LINE_SIZE - bytes_read);
		}
		print_offset(bytes_offset);
		ft_print_memory(buffer, LINE_SIZE);
		bytes_offset += bytes_read;
		ft_strncpy(buffer, "", sizeof(buffer));
		bytes_read = read(*file_descriptor, buffer, sizeof(buffer));
	}
	print_offset(bytes_offset);
	ft_putchar('\n');
}

void	ft_hexdump(int filecount, char **filenames)
{
	int		file_descriptor;

	file_descriptor = 0;
	while (filecount--)
	{
		if (*filenames)
			file_descriptor = open(*filenames, O_RDONLY);
		hexdump(&filecount, &filenames, &file_descriptor);
		if (*filenames)
			close(file_descriptor);
		filenames++;
	}
}
