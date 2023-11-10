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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*allocated;

	allocated = malloc(count * size);
	if (!allocated)
		return (NULL);
	ft_bzero(allocated, size * count);
	return (allocated);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_size;
	int		size;
	char	*join;

	s1_size = ft_strlen(s1);
	size = s1_size + ft_strlen(s2);
	join = ft_calloc((size + 1), sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcat(join, s1, s1_size + 1);
	ft_strlcat(join, s2, size + 1);
	return (join);
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
		return (ft_calloc(1, sizeof(char)));
	if (len > str_len)
		len = str_len;
	substr_len = min(start + len, str_len) - start;
	substr = ft_calloc(substr_len + 1, sizeof(char));
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

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	char	*aux;
	char	bytes_read;
	int		line_break_pos;

	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buffer)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		line_break_pos = buffer - ft_strchr(buffer, '\n');
		if (line_break_pos < ft_strlen(buffer) - 1) {
			break ;
		}
		aux = line;
		line = ft_strjoin(line, buffer);
		free(aux);
	}
	return (buffer);
}
