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

static char	*update_line(char *line, char *buffer, int nl_pos)
{
	char	*until_nl;
	char	*updated_line;
	int		i;

	if (!line)
		return (NULL);
	if (!buffer)
		return (free(line), NULL);
	if (nl_pos < 0)
		return (line);
	until_nl = malloc((nl_pos + 2) * sizeof(char));
	if (!until_nl)
		return (free(line), NULL);
	i = -1;
	while (++i < nl_pos + 1)
		until_nl[i] = buffer[i];
	until_nl[i] = '\0';
	updated_line = ft_strjoin(line, until_nl);
	if (!updated_line)
		return (free(line), free(until_nl), NULL);
	free(until_nl);
	free(line);
	line = updated_line;
	return (line);
}

static char	*update_buffer(char *buffer, int nl_pos)
{
	char	*substr;
	int		len;

	if (nl_pos == (int)ft_strlen(buffer) - 1)
	{
		buffer[0] = '\0';
		return (buffer);
	}
	substr = buffer + nl_pos + 1;
	len = ft_strlen(substr);
	ft_memmove(buffer, substr, len);
	buffer[len] = '\0';
	return (buffer);
}

static char	*update_state(char *buffer, char *line)
{
	int		nl_pos;
	char	*found;

	nl_pos = -1;
	found = ft_strchr(buffer, '\n');
	if (found)
		nl_pos = found - buffer;
	if (nl_pos >= 0)
	{
		line = update_line(line, buffer, nl_pos);
		buffer = update_buffer(buffer, nl_pos);
	}
	else
	{
		line = update_line(line, buffer, ft_strlen(buffer) - 1);
		buffer = update_buffer(buffer, ft_strlen(buffer) - 1);
	}
	return (line);
}

static void	init(int fd, char **buffer, char **line)
{
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (free_ptr(buffer));
	if (!*buffer)
	{
		*buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!*buffer)
			return ;
		*buffer[0] = '\0';
	}
	*line = malloc(1 * sizeof(char));
	if (!*line)
		return (free_ptr(buffer));
	*line[0] = '\0';
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			bytes_read;

	init(fd, &buffer, &line);
	if (!buffer || !line)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		line = update_state(buffer, line);
		if (!line || ft_strchr(line, '\n') != NULL)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
	}
	if (line && ft_strlen(line) == 0)
	{
		free_ptr(&buffer);
		free_ptr(&line);
	}
	else if (!line)
		free_ptr(&buffer);
	return (line);
}
