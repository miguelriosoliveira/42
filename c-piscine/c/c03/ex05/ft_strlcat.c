/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:44:46 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/09 11:44:48 by mrios-es         ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (src_len + size);
	i = 0;
	while (src[i] && i < size - dest_len - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
	char *src = "mundo";
	unsigned int i = 0;
	while (i <= 10) {
		char dest1[10] = "hola";
		char dest2[10] = "hola";
		printf("   strlcat(\"%s\", \"%s\", %d)", dest1, src, i);
		printf(": \"%s\" (%lu)", dest1,    strlcat(dest1, src, i));
		printf("\n");
		printf("ft_strlcat(\"%s\", \"%s\", %d)", dest2,  src, i);
		printf(": \"%s\" (%d)", dest2, ft_strlcat(dest2, src, i));
		printf("\n");
		printf("\n");
		i++;
	}

	char dest1[100] = "aaaaaaa";
	char dest2[100] = "aaaaaaa";
	src = "xyqwerrturerettw";
	i = 2;
	printf("   strlcat(\"%s\", \"%s\", %d)", dest1, src, i);
	printf(": \"%s\" (%lu)", dest1,    strlcat(dest1, src, i));
	printf("\n");
	printf("ft_strlcat(\"%s\", \"%s\", %d)", dest2,  src, i);
	printf(": \"%s\" (%d)",  dest2, ft_strlcat(dest2, src, i));
	printf("\n");
	printf("\n");
}
*/