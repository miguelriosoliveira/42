/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:02:16 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/05 12:02:21 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h>

int main(void) {
	char* word = "12345";
	printf("\"%s\" is numeric? %d\n", word, ft_str_is_numeric(word));
	
	word = "1234a";
	printf("\"%s\" is numeric? %d\n", word, ft_str_is_numeric(word));
	
	word = "";
	printf("\"%s\" is numeric? %d\n", word, ft_str_is_numeric(word));
	
	word = "3[4";
	printf("\"%s\" is numeric? %d\n", word, ft_str_is_numeric(word));

	return 0;
}
*/
