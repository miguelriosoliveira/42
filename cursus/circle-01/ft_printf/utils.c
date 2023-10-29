/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 00:23:55 by mrios-es          #+#    #+#             */
/*   Updated: 2023/10/12 00:25:00 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_padding(int size, char c)
{
	char	*padding;
	int		i;

	if (size <= 0)
		size = 0;
	padding = ft_calloc(size + 1, sizeof(char));
	if (!padding)
		return (NULL);
	i = 0;
	while (i < size)
	{
		padding[i] = c;
		i++;
	}
	return (padding);
}

int	print_padded(char *str, char *padding, int is_left_align)
{
	size_t	char_count;
	char	*first_str;
	char	*second_str;

	char_count = 0;
	first_str = padding;
	second_str = str;
	if (is_left_align)
	{
		first_str = str;
		second_str = padding;
	}
	char_count += ft_putstr_fd(first_str, 1);
	char_count += ft_putstr_fd(second_str, 1);
	if (char_count != ft_strlen(first_str) + ft_strlen(second_str))
		char_count = -1;
	return (char_count);
}

int	print_repeat(char c, int times)
{
	int	char_count;

	char_count = 0;
	while (times-- > 0)
		char_count += ft_putchar_fd(c, 1);
	return (char_count);
}

int	print_padded2(char *str, char pad_char, int pad_count, int is_left_align)
{
	size_t	char_count;

	char_count = 0;
	if (pad_count < 0)
		pad_count = 0;

	if (is_left_align)
	{
		char_count += ft_putstr_fd(str, 1);
		char_count += print_repeat(pad_char, pad_count);
	}
	else
	{
		char_count += print_repeat(pad_char, pad_count);
		char_count += ft_putstr_fd(str, 1);
	}

	if (char_count != ft_strlen(str) + pad_count)
		char_count = -1;
	return (char_count);
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
