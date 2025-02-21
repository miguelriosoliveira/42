/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:37:20 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/05 15:37:23 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

/*
#include <stdio.h>

int main(void) {
	char dest1[10];
	printf("Expected \"World!\" (len 6), got \"%s\" (len %d)",
		dest1,
		ft_strlcpy(dest1, "World!", 10));

	printf("\n");

	char dest2[10];
	printf("Expected \"Hello, Wo\" (len 9), got \"%s\" (len %d)",
		dest2,
		ft_strlcpy(dest2, "Hello, World!", 10));

	printf("\n");

	char dest3[5];
	printf("Expected \"Hell\" (len 4), got \"%s\" (len %d)",
		dest3,
		ft_strlcpy(dest3, "Hello, World!", 5));

	printf("\n");

	char dest4[10];
	printf("Expected \"\" (len 0), got \"%s\" (len %d)",
		dest4,
		ft_strlcpy(dest4, "", 5));

	printf("\n");

	char dest5[1];
	printf("Expected \"\" (len 0), got \"%s\" (len %d)",
		dest5,
		ft_strlcpy(dest5, "Hello, World!", 1));

	return 0;
}
*/
