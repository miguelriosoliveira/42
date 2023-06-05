/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:07:10 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/05 12:07:12 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h>

int main(void) {
	char* word = "lowercase";
	printf("\"%s\" is uppercase? %d\n", word, ft_str_is_uppercase(word));

	word = "UPPERCASE";
	printf("\"%s\" is uppercase? %d\n", word, ft_str_is_uppercase(word));

	word = "EmOcAsE";
	printf("\"%s\" is uppercase? %d\n", word, ft_str_is_uppercase(word));

	word = "";
	printf("\"%s\" is uppercase? %d\n", word, ft_str_is_uppercase(word));

	return 0;
}
*/
