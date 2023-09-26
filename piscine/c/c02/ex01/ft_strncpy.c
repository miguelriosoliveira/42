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
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main(void) {
	printf(">>> Test #1 <<<");
	printf("\n");
	printf("\n");

	char dst1_1[] = "aaaaa";
	char src1[] = "bbb";
	int n1 = 2;
	printf("   strncpy(\"%s\", ", dst1_1);
	char *strncpy_res1 = strncpy(dst1_1, src1, n1);
	printf("\"%s\", %d): %s", src1, n1, strncpy_res1);
	printf("\n");

	char dst1_2[] = "aaaaa";
	printf("ft_strncpy(\"%s\", ", dst1_2);
	char *ft_strncpy_res1 = ft_strncpy(dst1_2, src1, n1);
	printf("\"%s\", %d): %s", src1, n1, ft_strncpy_res1);
	printf("\n");
	 
	printf("\n");
	printf(">>> Test #2 <<<");
	printf("\n");
	printf("\n");

	char dst2_1[] = "aaaaa";
	char src2[] = "bbb";
	int n2 = 3;
	printf("   strncpy(\"%s\", ", dst2_1);
	char *strncpy_res2 = strncpy(dst2_1, src2, n2);
	printf("\"%s\", %d): %s", src2, n2, strncpy_res2);
	printf("\n");

	char dst2_2[] = "aaaaa";
	printf("ft_strncpy(\"%s\", ", dst2_2);
	char *ft_strncpy_res2 = ft_strncpy(dst2_2, src2, n2);
	printf("\"%s\", %d): %s", src2, n2, ft_strncpy_res2);
	printf("\n");
	 
	printf("\n");
	printf(">>> Test #3 <<<");
	printf("\n");
	printf("\n");

	char dst3_1[] = "aaaaa";
	char src3[] = "bbb";
	int n3 = 4;
	printf("   strncpy(\"%s\", ", dst3_1);
	char *strncpy_res3 = strncpy(dst3_1, src3, n3);
	printf("\"%s\", %d): %s", src3, n3, strncpy_res3);
	printf("\n");

	char dst3_2[] = "aaaaa";
	printf("ft_strncpy(\"%s\", ", dst3_2);
	char *ft_strncpy_res3 = ft_strncpy(dst3_2, src3, n3);
	printf("\"%s\", %d): %s", src3, n3, ft_strncpy_res3);
	printf("\n");
	 
	printf("\n");
	printf(">>> Test #4 <<<");
	printf("\n");
	printf("\n");

	char dst4_1[] = "aaaaa";
	char src4[] = "bbb";
	int n4 = 6;
	printf("   strncpy(\"%s\", ", dst4_1);
	char *strncpy_res4 = strncpy(dst4_1, src4, n4);
	printf("\"%s\", %d): %s", src4, n4, strncpy_res4);
	printf("\n");

	char dst4_2[] = "aaaaa";
	printf("ft_strncpy(\"%s\", ", dst4_2);
	char *ft_strncpy_res4 = ft_strncpy(dst4_2, src4, n4);
	printf("\"%s\", %d): %s", src4, n4, ft_strncpy_res4);
	printf("\n");
	 
	printf("\n");
	printf(">>> Test #5 <<<");
	printf("\n");
	printf("\n");

	char dst5_1[] = "ccc";
	char src5[] = "bbbbb";
	int n5 = 4;
	printf("   strncpy(\"%s\", ", dst5_1);
	char *strncpy_res5 = strncpy(dst5_1, src5, n5);
	printf("\"%s\", %d): %s", src5, n5, strncpy_res5);
	printf("\n");
	
	char dst5_2[] = "ccc";
	printf("ft_strncpy(\"%s\", ", dst5_2);
	char *ft_strncpy_res5 = ft_strncpy(dst5_2, src5, n5);
	printf("\"%s\", %d): %s", src5, n5, ft_strncpy_res5);
	printf("\n");
	 
	return 0;
}
*/