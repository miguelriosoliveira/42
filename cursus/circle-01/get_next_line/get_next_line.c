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

#include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_bzero(void *s, size_t n);
int		find_index(char *str, char c);
void	free_ptr(void *ptr);

static char	*update_line(char *line, char *buffer, int nl_pos)
{
	char	*until_nl;
	char	*updated_line;

	if (!line)
		return (NULL);

	if (!buffer)
		return (free(line), NULL);

	if (nl_pos < 0)
		return (line);

	// printf("[update_line]               line: \"%s\"\n", line);
	// printf("[update_line]             buffer: \"%s\"\n", buffer);
	// printf("[update_line]             nl_pos: %d\n", nl_pos);
	// printf("[update_line]          buffer[0]: \'%c\'\n", buffer[0]);
	// printf("[update_line] buffer[nl_pos + 1]: \'%c\'\n", buffer[nl_pos + 1]);

	until_nl = ft_substr(buffer, 0, nl_pos + 1);
	if (!until_nl)
		return (free(line), NULL);

	// printf("[update_line]           until_nl: \"%s\"\n", until_nl);
	// printf("[update_line]   line before join: \"%s\"\n", line);

	updated_line = ft_strjoin(line, until_nl);
	if (!updated_line)
		return (free(line), free(until_nl), NULL);

	// printf("[update_line]    line after join: \"%s\"\n", line);
	// printf("[update_line]       updated_line: \"%s\"\n", updated_line);

	free(until_nl);
	free(line);
	line = updated_line;

	// printf("[update_line]       updated line: \"%s\"\n", line);

	return (line);
}

static char	*update_buffer(char *buffer, int nl_pos)
{
	char	*substr;
	int		len;

	if (nl_pos == (int)ft_strlen(buffer) - 1)
	{
		ft_bzero(buffer, ft_strlen(buffer));
		return (buffer);
	}

	substr = buffer + nl_pos + 1;
	len = ft_strlen(substr);

	// printf("[update_buffer]     buffer: \"%s\"\n", buffer);
	// printf("[update_buffer]     substr: \"%s\"\n", substr);
	// printf("[update_buffer] substr_len: %d\n", len);

	ft_memmove(buffer, substr, len);
	ft_bzero(buffer + len, ft_strlen(buffer + len));
	return (buffer);
}

static char	*update_state(char *buffer, char *line)
{
	int	nl_pos;

	nl_pos = find_index(buffer, '\n');

	// printf("[update_state]         buffer: \"%s\"\n", buffer);
	// printf("[update_state]           line: \"%s\"\n", line);
	// printf("[update_state]         nl_pos: %d\n", nl_pos);

	if (nl_pos >= 0)
	{
		// printf("[update_state]       line before update: \"%s\"\n", line);
		line = update_line(line, buffer, nl_pos);
		// printf("[update_state]        line after update: \"%s\"\n", line);
		buffer = update_buffer(buffer, nl_pos);
		// printf("[update_state] line after buffer update: \"%s\"\n", line);
	}
	else
	{
		// printf("[update_state]       line before update: \"%s\"\n", line);
		line = update_line(line, buffer, ft_strlen(buffer) - 1);
		// printf("[update_state]        line after update: \"%s\"\n", line);
		buffer = update_buffer(buffer, ft_strlen(buffer) - 1);
		// printf("[update_state] line after buffer update: \"%s\"\n", line);
	}

	// printf("[update_state] updated buffer: \"%s\"\n", buffer);
	// printf("[update_state]   updated line: \"%s\"\n", line);

	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			nl_pos;
	int			bytes_read;

	// printf("[get_next_line] =========== BEGIN ===========\n");

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (NULL);

	if (!buffer)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
		ft_bzero(buffer, BUFFER_SIZE + 1);
	}

	line = malloc(1 * sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';

	bytes_read = 1;
	while (bytes_read > 0)
	{
		// printf("[get_next_line]         buffer: \"%s\"\n", buffer);
		// printf("[get_next_line]           line: \"%s\"\n", line);

		line = update_state(buffer, line);
		if (!line)
			break ;

		// printf("[get_next_line] updated buffer: \"%s\"\n", buffer);
		// printf("[get_next_line] updated   line: \"%s\"\n", line);

		nl_pos = find_index(line, '\n');
		if (nl_pos >= 0)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
	}

	if (line && ft_strlen(line) == 0)
	{
		if (buffer)
			free_ptr(&buffer);
		free(line);
		line = NULL;
	}

	// printf("[get_next_line]   final buffer: \"%s\"\n", buffer);
	// printf("[get_next_line]  returned line: \"%s\"\n", line);
	// printf("[get_next_line] ------------ END ------------\n");

	return (line);
}
