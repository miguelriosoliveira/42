/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:37:34 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/08 18:37:36 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (to_find[j] && str[i + j] == to_find[j])
				j++;
			if (to_find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>

int main() {
	char *str = "hello";
	char *to_find = "hello";
	printf("   strstr(\"%s\", \"%s\"): %s", str, to_find,    strstr(str, to_find));
	printf("\n");
	printf("ft_strstr(\"%s\", \"%s\"): %s", str, to_find, ft_strstr(str, to_find));
	printf("\n");
	
	str = "hhello";
	to_find = "hello";
	printf("   strstr(\"%s\", \"%s\"): %s", str, to_find,    strstr(str, to_find));
	printf("\n");
	printf("ft_strstr(\"%s\", \"%s\"): %s", str, to_find, ft_strstr(str, to_find));
	printf("\n");
	
	str = "yhellooooo";
	to_find = "hello";
	printf("   strstr(\"%s\", \"%s\"): %s", str, to_find,    strstr(str, to_find));
	printf("\n");
	printf("ft_strstr(\"%s\", \"%s\"): %s", str, to_find, ft_strstr(str, to_find));
	printf("\n");
}
*/