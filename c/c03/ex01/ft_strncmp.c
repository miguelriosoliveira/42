/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:40:22 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/08 17:40:24 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
	char *s1 = "hello";
	char *s2 = "hello";
	int n = 3;
	printf("   strncmp(\"%s\", \"%s\", %d): %d", s1, s2, n,    strncmp(s1, s2, n));
	printf("\n");
	printf("ft_strncmp(\"%s\", \"%s\", %d): %d", s1, s2, n, ft_strncmp(s1, s2, n));
	printf("\n");

	s1 = "hola";
	s2 = "hello";
	n = 3;
	printf("   strncmp(\"%s\", \"%s\", %d): %d", s1, s2, n,    strncmp(s1, s2, n));
	printf("\n");
	printf("ft_strncmp(\"%s\", \"%s\", %d): %d", s1, s2, n, ft_strncmp(s1, s2, n));
	printf("\n");

	s1 = "hello";
	s2 = "hola";
	n = 3;
	printf("   strncmp(\"%s\", \"%s\", %d): %d", s1, s2, n,    strncmp(s1, s2, n));
	printf("\n");
	printf("ft_strncmp(\"%s\", \"%s\", %d): %d", s1, s2, n, ft_strncmp(s1, s2, n));
	printf("\n");

	s1 = "holi";
	s2 = "hola";
	n = 4;
	printf("   strncmp(\"%s\", \"%s\", %d): %d", s1, s2, n,    strncmp(s1, s2, n));
	printf("\n");
	printf("ft_strncmp(\"%s\", \"%s\", %d): %d", s1, s2, n, ft_strncmp(s1, s2, n));
	printf("\n");

	s1 = "H0L4";
	s2 = "HOLA";
	n = 4;
	printf("   strncmp(\"%s\", \"%s\", %d): %d", s1, s2, n,    strncmp(s1, s2, n));
	printf("\n");
	printf("ft_strncmp(\"%s\", \"%s\", %d): %d", s1, s2, n, ft_strncmp(s1, s2, n));
	printf("\n");

	s1 = "H0L4";
	s2 = "HOLA";
	n = 6;
	printf("   strncmp(\"%s\", \"%s\", %d): %d", s1, s2, n,    strncmp(s1, s2, n));
	printf("\n");
	printf("ft_strncmp(\"%s\", \"%s\", %d): %d", s1, s2, n, ft_strncmp(s1, s2, n));
	printf("\n");
}
*/