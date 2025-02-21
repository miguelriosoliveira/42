/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:18:45 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/05 12:18:47 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	offset;
	int	i;

	offset = 'a' - 'A';
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += offset;
		i++;
	}
	return (str);
}

/*
#include <stdio.h>

int main(void) {
	char word1[] = "lowercase";
	printf("\"%s\" → ", word1);
  ft_strlowcase(word1);
	printf("\"%s\"\n", word1);

  char word2[] = "UPPERCASE";
	printf("\"%s\" → ", word2);
  ft_strlowcase(word2);
	printf("\"%s\"\n", word2);

  char word3[] = "EmOcAsE";
	printf("\"%s\" → ", word3);
  ft_strlowcase(word3);
	printf("\"%s\"\n", word3);

  char word4[] = "";
	printf("\"%s\" → ", word4);
  ft_strlowcase(word4);
	printf("\"%s\"\n", word4);

  char word5[] = "!#$abcDEF{|}~";
	printf("\"%s\" → ", word5);
  ft_strlowcase(word5);
	printf("\"%s\"\n", word5);

	return 0;
}
*/