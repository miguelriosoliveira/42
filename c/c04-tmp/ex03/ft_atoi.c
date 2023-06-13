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
	int	minus_count;

	i = 0;
	minus_count = 0;
	while (!is_numeric(str[i]))
	{
		if (str[i] == '-')
			minus_count++;
		i++;
	}
	result = 0;
	while (is_numeric(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (minus_count % 2)
		return (-result);
	return (result);
}

/*
#include <stdio.h>

int main() {
	char *str = " ---+--+1234ab567";
	printf("\"%s\"\n%d\n", str, ft_atoi(str));
	str = " ---+-+1234ab567";
	printf("\"%s\"\n%d\n", str, ft_atoi(str));
	return 0;
}
*/