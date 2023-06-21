/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:49:50 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/02 14:49:54 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

/*
#include <stdio.h>
int main(void) {
	char* word = "0123456789";
	int len = ft_strlen(word);
	printf("La palabra \"%s\" tiene %d caracteres.", word, len);
	return 0;
}
*/