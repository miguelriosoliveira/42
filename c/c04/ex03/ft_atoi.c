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

int	is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int	is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	includes(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		result;
	int		sign;
	char	*allowed_prefixes;

	i = 0;
	sign = 1;
	allowed_prefixes = "+-";
	while (str[i] && !is_printable(str[i]))
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && includes(str[i], allowed_prefixes))
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
	printf("ft_atoi(\"%s\"): %d", str, ft_atoi(str));
	printf("\n");
	printf("\n");

	str = " ---+-+1234ab567";
	printf("ft_atoi(\"%s\"): %d", str, ft_atoi(str));
	printf("\n");
	printf("\n");

	str = "a";
	printf("   atoi(\"%s\"): %d", str,    atoi(str));
	printf("\n");
	printf("ft_atoi(\"%s\"): %d", str, ft_atoi(str));
	printf("\n");
	printf("\n");

	str = "abc123";
	printf("   atoi(\"%s\"): %d", str,    atoi(str));
	printf("\n");
	printf("ft_atoi(\"%s\"): %d", str, ft_atoi(str));
	printf("\n");
	return 0;
}
*/