/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:47:31 by mrios-es          #+#    #+#             */
/*   Updated: 2023/10/24 23:10:36 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	print_nbr(int nbr, t_flags *flags)
{
	char	*num_str;
	char	*pad;
	char	*join;
	int		num_len;
	// int		n_written;
	int		char_count;
	int		is_negative;
	int		is_negative_zeropad;

	num_str = ft_itoa(nbr);
	if (!num_str)
		return (-1);
	if (flags->precision >= 0)
		flags->pad_char = ' ';
	is_negative = nbr < 0;
	pad = create_padding(flags->precision - ft_strlen(num_str) + is_negative + 1, '0');
	if (!pad)
	{
		free(num_str);
		return (-1);
	}
	if (is_negative)
	{
		pad[0] = '-';
		join = ft_strjoin(pad, num_str + 1);
	}
	else
		join = ft_strjoin(pad, num_str);
	free(pad);
	free(num_str);
	num_str = join;
	if (!join)
		return (-1);
	num_len = ft_strlen(num_str);
	char_count = 0;

	is_negative_zeropad = nbr < 0 && flags->pad_char == '0';
	if (is_negative_zeropad)
	{
		char_count += ft_putchar_fd('-', 1);
		// n_written = ft_putchar_fd('-', 1);
		// if (n_written == -1)
		// {
		// 	free(num_str);
		// 	return (-1);
		// }
		// char_count += n_written;

	// printf("\n");
		// printf("[before] num_str: \"%s\"\n", num_str);

		ft_memmove(num_str, num_str + 1, num_len);
		// num_len--;
		flags->min_width--;

		// printf("[after ] num_str: \"%s\"\n", num_str);
	}
	// char_count += print_str(num_str, flags);
	pad = create_padding(flags->min_width - ft_strlen(num_str), flags->pad_char);
	if (!pad)
	{
		free(num_str);
		return (-1);
	}
	char_count += print_padded(num_str, pad, flags->left_align);
	free(pad);
	// n_written = print_str(num_str, flags);
	// if (n_written == -1)
	// 	return (-1);
	// char_count += n_written;

	// printf("\n");
	// printf("                    char_count: %d\n", char_count);
	// printf("                       num_str: \"%s\"\n", num_str);
	// printf("                       num_len: %d\n", num_len);
	// printf("              flags->min_width: %d\n", flags->min_width);
	// printf("              flags->precision: %d\n", flags->precision);
	// printf("max(num_len, flags->min_width + is_negative_zeropad): %d\n", max(num_len, flags->min_width + is_negative_zeropad));

	free(num_str);
	if (char_count != max(num_len, flags->min_width + is_negative_zeropad))
		return (-1);

	return (char_count);
}
