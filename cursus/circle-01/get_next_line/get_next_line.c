/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:18:09 by mrios-es          #+#    #+#             */
/*   Updated: 2023/11/10 18:18:09 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	int		bytes_read;
	char	c;
	int		i;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &c, 0) < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	bytes_read = read(fd, &c, 1);
	while (bytes_read)
	{
		buffer[i] = c;
		i++;
		if (c == '\n' || c == '\0')
			break ;
		bytes_read = read(fd, &c, 1);
	}
	if (i == 0 || bytes_read < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}
