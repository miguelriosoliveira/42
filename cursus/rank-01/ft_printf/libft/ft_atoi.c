/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:05:10 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/13 19:05:10 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (ft_strchr("\t\n\v\f\r ", c) != NULL);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	sign = 1;
	while (str[i] && is_space(str[i]))
		i++;
	if (ft_strchr("+-", str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (sign * result);
}
