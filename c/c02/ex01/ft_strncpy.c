/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:44:42 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/05 09:44:44 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main(void) {
	char dst1[] = "World1";
	char src1[] = "Hello";
	int n1 = 3;
	char *strncpy_res1 = strncpy(dst1, src1, n1);
	char *ft_strncpy_res1 = ft_strncpy(dst1, src1, n1);
	printf("   strncpy \"%s\" \"%s\" %d: %s\n", dst1, src1, n1,    strncpy_res1);
	printf("ft_strncpy \"%s\" \"%s\" %d: %s\n", dst1, src1, n1, ft_strncpy_res1);
	
	printf("\n");

	char dst2[] = "World1";
	char src2[] = "Hello";
	int n2 = 5;
	char *strncpy_res2 = strncpy(dst2, src2, n2);
	char *ft_strncpy_res2 = ft_strncpy(dst2, src2, n2);
	printf("   strncpy \"%s\" \"%s\" %d: %s\n", dst2, src2, n2,    strncpy_res2);
	printf("ft_strncpy \"%s\" \"%s\" %d: %s\n", dst2, src2, n2, ft_strncpy_res2);

	printf("\n");
	
	char dst3[] = "World1";
	char src3[] = "Hello";
	int n3 = 7;
	char *strncpy_res3 = strncpy(dst3, src3, n3);
	char *ft_strncpy_res3 = ft_strncpy(dst3, src3, n3);
	printf("   strncpy \"%s\" \"%s\" %d: %s\n", dst3, src3, n3,    strncpy_res3);
	printf("ft_strncpy \"%s\" \"%s\" %d: %s\n", dst3, src3, n3, ft_strncpy_res3);
	 
	return 0;
}
*/
