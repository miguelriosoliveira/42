/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:05:12 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/13 19:05:12 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*to_find;

	i = 0;
	str = (char *)haystack;
	to_find = (char *)needle;
	if (to_find[0] == '\0')
		return (str);
	while (i < len && str[i])
	{

		// printf("    str[%2zu]: '%c'\n", i, str[i]);
		// printf("to_find[ 0]: '%c'\n", to_find[0]);

		if (str[i] == to_find[0])
		{

			// printf("match!\n");

			j = 0;
			while (i + j < len && to_find[j] && str[i + j] == to_find[j])
			{
				// printf("    str[%2zu]: '%c'\n", i + j, str[i + j]);
				// printf("to_find[%2zu]: '%c'\n", j, to_find[j]);
				j++;
			}
				// printf("    str[%2zu]: '%c'\n", i + j, str[i + j]);
				// printf("to_find[%2zu]: '%c'\n", j, to_find[j]);
			if (to_find[j] == '\0')
			{
				// printf("to_find finished!\n");
				// printf("return value: \"%s\"\n", &str[i]);
				return (&str[i]);
			}

			// printf("we have to keep looking!\n");
		}
		i++;
	}
			// printf("before returning null!\n");
	return (NULL);
}
