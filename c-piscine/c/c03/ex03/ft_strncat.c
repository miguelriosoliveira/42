/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:31:16 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/08 18:31:19 by mrios-es         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i] && i < nb)
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
	int n = 3;
	printf("   strncat(\"%s\"", dest1_1);
	printf(", \"%s\", %d): %s", src, n,    strncat(dest1_1, src, n));
	printf("\n");
	printf("ft_strncat(\"%s\"", dest1_2);
	printf(", \"%s\", %d): %s", src, n, ft_strncat(dest1_2, src, n));
	printf("\n");

	char dest2_1[10] = "hola";
	char dest2_2[10] = "hola";
	src = "mundo";
	n = 4;
	printf("   strncat(\"%s\"", dest2_1);
	printf(", \"%s\", %d): %s", src, n,    strncat(dest2_1, src, n));
	printf("\n");
	printf("ft_strncat(\"%s\"", dest2_2);
	printf(", \"%s\", %d): %s", src, n, ft_strncat(dest2_2, src, n));
	printf("\n");

	char dest3_1[10] = "hola";
	char dest3_2[10] = "hola";
	src = "mundo";
	n = 7;
	printf("   strncat(\"%s\"", dest3_1);
	printf(", \"%s\", %d): %s", src, n,    strncat(dest3_1, src, n));
	printf("\n");
	printf("ft_strncat(\"%s\"", dest3_2);
	printf(", \"%s\", %d): %s", src, n, ft_strncat(dest3_2, src, n));
	printf("\n");
}
*/