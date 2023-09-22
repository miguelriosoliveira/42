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
	if (parts_count == 0)
		parts_count++;
	parts = ft_calloc((parts_count + 1), sizeof(char *));
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

static char	*alloc_word(char *str, char c)
{
	int		i;
	int		size;
	char	*word;

	size = count_valid_chars(str, c);
	if (size == 0)
		return (NULL);
	word = ft_calloc(size + 1, sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < size)
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**parts;
	char	*str;

	str = (char *)s;
	parts = alloc_parts(str, c);
	if (!parts)
		return (NULL);
	if (ft_strlen(str) == 0)
		return (parts);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		parts[j] = alloc_word(&str[i], c);
		j++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (parts);
}
