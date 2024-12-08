/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:21:55 by mrios-es          #+#    #+#             */
/*   Updated: 2024/08/22 22:49:19 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_size;
	int		size;
	char	*join;
	int		i;

	s1_size = ft_strlen(s1);
	size = s1_size + ft_strlen(s2);
	join = malloc((size + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (i < s1_size)
	{
		join[i] = s1[i];
		i++;
	}
	while (i < size)
	{
		join[i] = s2[i - s1_size];
		i++;
	}
	join[i] = '\0';
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

void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
