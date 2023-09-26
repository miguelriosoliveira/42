/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:04:50 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/05 12:04:55 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h>

int main(void) {
	char* word = "lowercase";
	printf("\"%s\" is lowercase? %d\n", word, ft_str_is_lowercase(word));
	
	word = "UPPERCASE";
	printf("\"%s\" is lowercase? %d\n", word, ft_str_is_lowercase(word));
	
	word = "EmOcAsE";
	printf("\"%s\" is lowercase? %d\n", word, ft_str_is_lowercase(word));
	
	word = "";
	printf("\"%s\" is lowercase? %d\n", word, ft_str_is_lowercase(word));

	return 0;
}
*/