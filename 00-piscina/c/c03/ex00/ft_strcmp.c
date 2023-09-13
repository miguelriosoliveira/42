/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:14:00 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/06 14:14:04 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
	char *s1 = "hello";
	char *s2 = "hello";
	printf("   strcmp(\"%s\", \"%s\"): %d", s1, s2,    strcmp(s1, s2));
	printf("\n");
	printf("ft_strcmp(\"%s\", \"%s\"): %d", s1, s2, ft_strcmp(s1, s2));
	printf("\n");

	s1 = "hola";
	s2 = "hello";
	printf("   strcmp(\"%s\", \"%s\"): %d", s1, s2,    strcmp(s1, s2));
	printf("\n");
	printf("ft_strcmp(\"%s\", \"%s\"): %d", s1, s2, ft_strcmp(s1, s2));
	printf("\n");

	s1 = "hello";
	s2 = "hola";
	printf("   strcmp(\"%s\", \"%s\"): %d", s1, s2,    strcmp(s1, s2));
	printf("\n");
	printf("ft_strcmp(\"%s\", \"%s\"): %d", s1, s2, ft_strcmp(s1, s2));
	printf("\n");

	s1 = "holi";
	s2 = "hola";
	printf("   strcmp(\"%s\", \"%s\"): %d", s1, s2,    strcmp(s1, s2));
	printf("\n");
	printf("ft_strcmp(\"%s\", \"%s\"): %d", s1, s2, ft_strcmp(s1, s2));
	printf("\n");

	s1 = "hol1";
	s2 = "hola";
	printf("   strcmp(\"%s\", \"%s\"): %d", s1, s2,    strcmp(s1, s2));
	printf("\n");
	printf("ft_strcmp(\"%s\", \"%s\"): %d", s1, s2, ft_strcmp(s1, s2));
	printf("\n");
}
*/