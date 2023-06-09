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

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
	char dest1_1[11] = "hello";
	char dest1_2[11] = "hello";
	char *src = "world";
	printf("   strcat(\"%s\"", dest1_1);
	printf(", \"%s\"): %s", src,    strcat(dest1_1, src));
	printf("\n");
	printf("ft_strcat(\"%s\"", dest1_2);
	printf(", \"%s\"): %s", src, ft_strcat(dest1_2, src));
	printf("\n");

	char dest2_1[10] = "hola";
	char dest2_2[10] = "hola";
	src = "mundo";
	printf("   strcat(\"%s\"", dest2_1);
	printf(", \"%s\"): %s", src,    strcat(dest2_1, src));
	printf("\n");
	printf("ft_strcat(\"%s\"", dest2_2);
	printf(", \"%s\"): %s", src, ft_strcat(dest2_2, src));
	printf("\n");
}
*/