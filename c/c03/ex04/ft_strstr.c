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

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;
	int	to_find_len;
	int	match_pos;

	to_find_len = ft_strlen(to_find);
	if (to_find_len == 0)
		return (str);
	i = 0;
	while (str[i])
	{
		j = i;
		while (str[j] != to_find[0])
			j++;
		match_pos = j;
		k = 0;
		while (str[j + k] && str[j + k] == to_find[k])
			k++;
		if (k == to_find_len)
			return (&str[match_pos]);
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