/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:29:11 by mguardia          #+#    #+#             */
/*   Updated: 2023/06/18 16:05:49 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

void	count_num_chars(int num, int count, int *total_char)
{
	int	len_zeros;

	len_zeros = count_zeros(count);
	if (num <= 9)
	{
		*total_char += 1;
		while (count > 1000 && is_multiple_1000(count))
			count /= 1000;
		if (count >= 100)
			*total_char += len_zeros + 2;
	}
	else if (num < 100)
	{
		count_num_chars(num / 10, count * 10, total_char);
		count_num_chars(num % 10, count, total_char);
	}
	else
	{
		count_num_chars(num / 10, count * 10, total_char);
		count_num_chars(num % 10, count, total_char);
	}
}

void	fill_count_chars(int count, char *str)
{
	int	str_len;

	if (count <= 9)
	{
		str_len = ft_strlen(str);
		str[str_len++] = count + '0';
	}
	else if (count < 100)
	{
		fill_count_chars(count / 10, str);
		fill_count_chars(count % 10, str);
	}
	else
	{
		fill_count_chars(count / 10, str);
		fill_count_chars(count % 10, str);
	}
}

void	fill_num_chars(int num, int count, char *str)
{
	if (num <= 9)
	{
		str[ft_strlen(str)] = num + '0';
		while (count > 1000 && is_multiple_1000(count))
			count /= 1000;
		if (count >= 100)
		{
			str[ft_strlen(str)] = '-';
			fill_count_chars(count, str);
			str[ft_strlen(str)] = '-';
		}
	}
	else if (num < 100)
	{
		fill_num_chars(num / 10, count * 10, str);
		fill_num_chars(num % 10, count, str);
	}
	else
	{
		fill_num_chars(num / 10, count * 10, str);
		fill_num_chars(num % 10, count, str);
	}
}
