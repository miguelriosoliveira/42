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

#include <stdio.h>

char	**alloc_parts(char *str, char c)
{
	int		i;
	int		parts_count;
	int		checkpoint;
	char	**parts;

	i = 0;
	parts_count = 0;
	while (str[i])
	{
		// printf("        str[%2d]: '%c'\n", i, str[i]);

		while (str[i] && str[i] == c)
		{
			// printf("[ is c] str[%2d]: '%c'\n", i, str[i]);
			i++;
		}
		checkpoint = i;
		while (str[i] && str[i] != c)
		{
			// printf("[not c] str[%2d]: '%c'\n", i, str[i]);
			i++;
		}
		parts_count += i > checkpoint;
	}

	printf("i: %d\n", i);
	printf("parts_count: %d\n", parts_count);

	parts = ft_calloc((parts_count + 1), sizeof(char *));
	return (parts);
}

int	count_valid_chars(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*alloc_word(char *str, char c)
{
	int		i;
	int		current_part_len;
	char	*current_part;

	current_part_len = count_valid_chars(str, c);
	current_part = ft_calloc((current_part_len + 1), sizeof(char));
	i = 0;
	while (i < current_part_len)
	{
		current_part[i] = str[i];
		i++;
	}
	return (current_part);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**parts;
	char	*str;

	// if (!s)
	// 	return (NULL);
	str = (char *)s;

	printf("str: \"%s\"\n", str);

	parts = alloc_parts(str, c);
	i = 0;
	j = 0;
	// while (str[i])
	// {
	// 	if (str[i] != c && (!str[i - 1] || str[i - 1] == c))
	// 	{
	// 		parts[j] = alloc_word(&str[i], c);
	// 		j++;
	// 	}
	// 	i++;
	// }
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
