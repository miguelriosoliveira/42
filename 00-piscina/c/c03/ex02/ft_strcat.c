/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:54:56 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/08 17:54:58 by mrios-es         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
	char dest1_1[11] = "hello";
	char dest1_2[11] = "hello";
	char *src = "world";
	printf("   strcat(\"%s\", \"%s\")", dest1_1, src);
	printf(": \"%s\"",    strcat(dest1_1, src));
	printf("\n");
	printf("ft_strcat(\"%s\", \"%s\")", dest1_2, src);
	printf(": \"%s\"", ft_strcat(dest1_2, src));
	printf("\n");
	printf("\n");

	char dest2_1[10] = "hola";
	char dest2_2[10] = "hola";
	src = "mundo";
	printf("   strcat(\"%s\", \"%s\")", dest2_1, src);
	printf(": \"%s\"",    strcat(dest2_1, src));
	printf("\n");
	printf("ft_strcat(\"%s\", \"%s\")", dest2_2, src);
	printf(": \"%s\"", ft_strcat(dest2_2, src));
	printf("\n");
	printf("\n");

	char dest3_1[11] = "42l33r";
	char dest3_2[] = "42l33r";
	src = "l33r";
	printf("   strcat(\"%s\", \"%s\")", dest3_1, src);
	printf(": \"%s\"",    strcat(dest3_1, src));
	printf("\n");
	printf("ft_strcat(\"%s\", \"%s\")", dest3_2, src);
	printf(": \"%s\"", ft_strcat(dest3_2, src));
	printf("\n");
}
*/