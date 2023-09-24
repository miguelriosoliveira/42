/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:05:11 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/13 19:05:11 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**alloc_parts(char *str, char c)
{
	int		i;
	int		parts_count;
	int		checkpoint;
	char	**parts;

	i = 0;
	parts_count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		checkpoint = i;
		while (str[i] && str[i] != c)
			i++;
		parts_count += i > checkpoint;
	}
	parts = ft_calloc(parts_count + 1, sizeof(char *));
	if (!parts)
		return (NULL);
	return (parts);
}

static int	count_valid_chars(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void	free_parts(char **parts, int j)
{
	while (j--)
		free(parts[j]);
	free(parts);
}

static char	**fill_parts(char **parts, char *str, char c)
{
	int		i;
	int		j;
	int		valid_char_count;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		valid_char_count = count_valid_chars(&str[i], c);
		if (valid_char_count > 0)
		{
			parts[j] = ft_substr(str, i, valid_char_count);
			if (!parts[j])
			{
				free_parts(parts, j);
				return (NULL);
			}
			j++;
		}
		while (str[i] && str[i] != c)
			i++;
	}
	return (parts);
}

char	**ft_split(char const *s, char c)
{
	char	**parts;
	char	*str;

	str = (char *)s;
	if (!str)
		return (NULL);
	parts = alloc_parts(str, c);
	if (!parts)
		return (NULL);
	parts = fill_parts(parts, str, c);
	return (parts);
}
