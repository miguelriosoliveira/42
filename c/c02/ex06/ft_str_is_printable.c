/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:09:23 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/05 12:09:26 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 127))
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h>

int main(void) {
	char* word = "lowercase";
	printf("\"%s\" is printable? %d\n", word, ft_str_is_printable(word));

	word = "UPPERCASE";
	printf("\"%s\" is printable? %d\n", word, ft_str_is_printable(word));

	word = "EmOcAsE";
	printf("\"%s\" is printable? %d\n", word, ft_str_is_printable(word));

	word = "";
	printf("\"%s\" is printable? %d\n", word, ft_str_is_printable(word));

	word = "\n";
	printf("\"%s\" is printable? %d\n", word, ft_str_is_printable(word));

	return 0;
}
*/
