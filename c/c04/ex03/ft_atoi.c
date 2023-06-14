/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:53:56 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/13 13:53:57 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] && !is_numeric(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (str[i] && is_numeric(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (sign * result);
}

/*
#include <stdio.h>
#include <stdlib.h>

int main() {
	char *str;
	str = " ---+--+1234ab567";
	printf("ft_atoi(\"%s\"): %d\n\n", str, ft_atoi(str));

	str = " ---+-+1234ab567";
	printf("ft_atoi(\"%s\"): %d\n\n", str, ft_atoi(str));

	str = "a";
	printf("   atoi(\"%s\"): %d\n",   str,    atoi(str));
	str = "a";
	printf("ft_atoi(\"%s\"): %d\n", str, ft_atoi(str));
	return 0;
}
*/