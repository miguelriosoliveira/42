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
		return a;
	return b;
}

void	hexdump(int filecount, char **filenames)
{
	int		file_descriptor;
	int		i;
	int		j;
	int		k;
	char	buffer[BLOCK_SIZE];
	int		bytes_read;
	char 	*filename;

	file_descriptor = 0;
	k = 0;
	while (k < filecount)
	{
		filename = filenames[k];

		if (filename)
			file_descriptor = open(filename, O_RDONLY);
		bytes_read = read(file_descriptor, buffer, sizeof(buffer));
		i = 0;
		while (bytes_read > 0)
		{
			j = 0;
			while (buffer[j] && j < min(bytes_read, BLOCK_SIZE))
			{
				if (ft_strlen(&buffer[j]) < LINE_SIZE && bytes_read < BLOCK_SIZE)
				{
					// ft_putstr("[antes ] &buffer[j]: ");
					// ft_putstr(&buffer[j]);
					// ft_putstr("\n");

					close(file_descriptor);
					k++;
					filename = filenames[k];
					file_descriptor = open(filename, O_RDONLY);
					bytes_read = read(file_descriptor, &buffer[j + ft_strlen(&buffer[j])], LINE_SIZE - ft_strlen(&buffer[j]));

					// ft_putstr("- j: ");
					// ft_putnbr_base(j, "0123456789", 3);
					// ft_putstr(" - time to open a new file?\n");
					// ft_putstr("[depois] &buffer[j]: ");
					// ft_putstr(&buffer[j]);
					// ft_putstr("\n");
				}

				ft_putnbr_base(i, "0123456789abcdef", 8);
				ft_print_memory(&buffer[j], LINE_SIZE);
				i += min(ft_strlen(&buffer[j]), LINE_SIZE);
				j += min(ft_strlen(&buffer[j]), LINE_SIZE);
			}
			if (ft_strlen(&buffer[j]) < LINE_SIZE)
			{
				// if (bytes_read < BLOCK_SIZE)
				// {
				// 	k++;
				// 	filename = filenames[k];
				// 	file_descriptor = open(filename, O_RDONLY);
				// 	bytes_read = read(file_descriptor, &buffer[j], LINE_SIZE - ft_strlen(&buffer[j]));

				// 	ft_putstr("- j: ");
				// 	ft_putnbr_base(j, "0123456789", 3);
				// 	ft_putstr(" - time to open a new file?\n");
				// }
				ft_strncpy(buffer, "", sizeof(buffer));
			}
			bytes_read = read(file_descriptor, buffer, sizeof(buffer));
		}
		ft_putnbr_base(i, "0123456789abcdef", 8);
		ft_putchar('\n');
		if (filename)
			close(file_descriptor);

		k++;
	}
}

// void	ft_hexdump(int filecount, char **filenames)
// {
// 	char	*filename;
// 	int		i;

// 	i = 0;
// 	while (i < filecount)
// 	{
// 		filename = filenames[i];
// 		if (check_file(filename))
// 			hexdump(filename);
// 		i++;
// 	}
// }
void	ft_hexdump(int filecount, char **filenames)
{
	hexdump(filecount, filenames);
}
