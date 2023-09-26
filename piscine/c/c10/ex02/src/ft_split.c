/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:46:50 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/29 19:46:58 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	**alloc_parts(char *str, char *charset)
{
	int		i;
	int		parts_count;
	char	**parts;

	i = 0;
	parts_count = 0;
	while (str[i])
	{
		if (!includes(str[i], charset)
			&& (str[i + 1] || includes(str[i + 1], charset)))
			parts_count++;
		i++;
	}
	parts = malloc((parts_count + 1) * sizeof(char *));
	parts[parts_count] = 0;
	return (parts);
}

int	count_valid_chars(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !includes(str[i], charset))
		i++;
	return (i);
}

char	*alloc_part(char *str, char *charset)
{
	int		i;
	int		current_part_len;
	char	*current_part;

	current_part_len = count_valid_chars(str, charset);
	current_part = malloc((current_part_len + 1) * sizeof(char));
	current_part[current_part_len] = '\0';
	i = 0;
	while (i < current_part_len)
	{
		current_part[i] = str[i];
		i++;
	}
	return (current_part);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**parts;

	parts = alloc_parts(str, charset);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!includes(str[i], charset)
			&& (!str[i - 1] || includes(str[i - 1], charset)))
		{
			parts[j] = alloc_part(&str[i], charset);
			j++;
		}
		i++;
	}
	return (parts);
}

/*
#include <stdio.h>
int main() {
	char *input[][2] = {
		{"", ""},
		{"hello", ""},
		{",,hello,world,,", ","},
		{"hello,,,,world", ","},
		{"aaabbbaaaccc", "ab"},
		{NULL}
	};
	int i = 0;
	while (input[i][0]) {
		char *str = input[i][0];
		char *charset = input[i][1];
		char **parts = ft_split(str, charset);
		printf("ft_split(\"%s\", \"%s\"): [\"%s\"", str, charset, parts[0]);
		int j = 1;
		while (parts[j]) {
			printf(", \"%s\"", parts[j]);
			j++;
		}
		printf("]");
		printf("\n");
		printf("\n");
		i++;
	}

	return 0;
}
*/
