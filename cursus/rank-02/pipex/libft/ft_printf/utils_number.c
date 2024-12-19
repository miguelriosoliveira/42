/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 00:23:55 by mrios-es          #+#    #+#             */
/*   Updated: 2023/10/12 00:25:00 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	count_num_len(int nbr)
{
	int	count;

	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr *= -1;
	count = 0;
	while (nbr)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

int	count_unum_len(unsigned int nbr)
{
	int	count;

	if (nbr == 0)
		return (1);
	count = 0;
	while (nbr)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

int	count_base_len(unsigned int nbr, char *base)
{
	int	char_count;
	int	base_len;

	if (nbr == 0)
		return (1);
	base_len = ft_strlen(base);
	char_count = 0;
	while (nbr > 0)
	{
		char_count++;
		nbr /= base_len;
	}
	return (char_count);
}
