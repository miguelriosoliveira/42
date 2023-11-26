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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	chr;

	i = 0;
	str = (char *)s;
	chr = c;
	while (str[i])
	{
		if (str[i] == chr)
			return (&str[i]);
		i++;
	}
	if (chr == '\0')
		return (&str[i]);
	return (NULL);
}

int	find_index(char *str, char c)
{
	char *found;

	// printf("str: \"%s\"\n", str);
	// printf("c: '%c'\n", c);

	found = ft_strchr(str, c);

	// printf("found: \"%s\"\n", found);

	if (!found)
		return (-1);
	return (found - str);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;
	int		substr_len;
	int		i;

	str_len = ft_strlen(s);
	if (start >= str_len)
		return (malloc(1 * sizeof(char)));
	if (len > str_len)
		len = str_len;
	substr_len = min(start + len, str_len) - start;
	substr = malloc(substr_len + 1 * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < substr_len)
	{
		substr[i] = s[i + start];
		i++;
	}
	return (substr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	i = 0;
	while (src[i] && i < dstsize - dst_len - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_size;
	int		size;
	char	*join;

	s1_size = ft_strlen(s1);
	size = s1_size + ft_strlen(s2);
	join = malloc((size + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcat(join, s1, s1_size + 1);
	ft_strlcat(join, s2, size + 1);
	return (join);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dest;
	const char	*source;

	if (!dst && !src)
		return (NULL);
	dest = dst;
	source = src;
	if (dest > source)
	{
		while (len--)
			dest[len] = source[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}



char	*update_line(char *line, char *buffer, int nl_pos)
{
	char	*aux;
	char	*until_nl;

	if (!line || !buffer || nl_pos < 0)
		return (line);
	until_nl = ft_substr(buffer, 0, nl_pos + 1);
	if (!until_nl)
		return (line);
	aux = line;

	printf("[update_line] line: \"%s\"\n", line);
	printf("[update_line] buffer: \"%s\"\n", buffer);
	printf("[update_line] nl_pos: %d\n", nl_pos);
	printf("[update_line] until_nl: \"%s\"\n", until_nl);

	line = ft_strjoin(line, until_nl);

	printf("[update_line] line: \"%s\"\n", line);

	free(until_nl);
	free(aux);


	return (line);
}

void	update_buffer(char *buffer, int nl_pos)
{
	ft_memmove(buffer, buffer + nl_pos, ft_strlen(buffer + nl_pos));
	ft_bzero(buffer + nl_pos, ft_strlen(buffer + nl_pos));
}

char	*update_state(char *buffer, char *line)
{
	int	nl_pos;

	nl_pos = find_index(buffer, '\n');

	printf("[update_state] buffer: \"%s\"\n", buffer);
	printf("[update_state] line: \"%s\"\n", line);
	printf("[update_state] nl_pos: %d\n", nl_pos);

	if (nl_pos >= 0)
	{
		line = update_line(line, buffer, nl_pos);
		update_buffer(buffer, nl_pos);
	}
	else
		line = update_line(line, buffer, ft_strlen(buffer));

	printf("[update_state] updated line: \"%s\"\n", line);

	return (line);
}

/*
	se buffer tiver algum resíduo
		se buffer tiver um \n
			concatena a primeira parte (até o \n) do bufer ao final de LINE
			buffer passa a ser sua segunda parte (após o \n)
			retorna LINE
		senão
			concatena buffer ao final da variável LINE

	enquanto tiver coisas para ler
		lê bloco de chars para dentro do buffer
		se buffer tiver um \n
			concatena a primeira parte (até o \n) do bufer ao final de LINE
			buffer passa a ser sua segunda parte (após o \n)
			retorna LINE
		senão
			concatena buffer ao final da variável LINE

	se tiver algo em LINE
		retorna LINE
	senão
		retorna NULL
*/
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	int			nl_pos;

	if (fd) {}

	line = malloc(1 * sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (ft_strlen(buffer) > 0)
	{
		// nl_pos = find_index(buffer, '\n');
		// if (nl_pos >= 0)
		// {
		// 	line = update_line(line, buffer, nl_pos);
		// 	update_buffer(buffer, nl_pos);
		// 	return (line);
		// }
		// else
		// 	line = update_line(line, buffer, 0);
		line = update_state(buffer, line);
		if (line)
			return (line);
	}

	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		printf("[get_next_line] buffer: \"%s\"\n", buffer);

		line = update_state(buffer, line);

		printf("[get_next_line] line: \"%s\"\n", line);

		nl_pos = find_index(buffer, '\n');
		if (nl_pos >= 0)
			break ;

	}


	if (ft_strlen(line) > 0)
		return (line);
	return (NULL);
}
