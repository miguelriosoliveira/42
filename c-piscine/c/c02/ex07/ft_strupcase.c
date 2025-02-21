/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:15:10 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/05 12:15:13 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	offset;
	int	i;

	offset = 'a' - 'A';
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= offset;
		i++;
	}
	return (str);
}

/*
#include <stdio.h>

int main(void) {
	char word1[] = "lowercase";
	printf("\"%s\" → ", word1);
  ft_strupcase(word1);
	printf("\"%s\"\n", word1);

  char word2[] = "UPPERCASE";
	printf("\"%s\" → ", word2);
  ft_strupcase(word2);
	printf("\"%s\"\n", word2);

  char word3[] = "EmOcAsE";
	printf("\"%s\" → ", word3);
  ft_strupcase(word3);
	printf("\"%s\"\n", word3);

  char word4[] = "";
	printf("\"%s\" → ", word4);
  ft_strupcase(word4);
	printf("\"%s\"\n", word4);

  char word5[] = "!#$abc{|}~";
	printf("\"%s\" → ", word5);
  ft_strupcase(word5);
	printf("\"%s\"\n", word5);

	return 0;
}
*/