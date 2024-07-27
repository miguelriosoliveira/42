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

static int	print_number_with_precision(long nbr, t_flags *flags)
{
	int	char_count;
	int	is_negative;
	int	num_len;
	int	pad_count;

	char_count = 0;
	is_negative = nbr < 0;
	if (is_negative)
	{
		char_count += ft_putchar_fd('-', 1);
		nbr *= -1;
	}
	else if (flags->signed_form)
		char_count += ft_putchar_fd('+', 1);
	else if (flags->space_sign)
		char_count += ft_putchar_fd(' ', 1);
	if (nbr == 0 && flags->pad_char != '0' && flags->precision == 0)
		return (char_count);
	num_len = count_num_len(nbr);
	pad_count = max(flags->precision - num_len, 0);
	char_count += print_repeat('0', pad_count);
	char_count += ft_putnbr_fd(nbr, 1);
	return (char_count);
}

static void	update_flags(int nbr, t_flags *flags)
{
	int	is_negative;
	int	width_change;

	is_negative = nbr < 0;
	width_change = min(is_negative + flags->signed_form + flags->space_sign, 1);
	if (flags->pad_char == '0')
	{
		if (flags->precision < 0)
			flags->precision = flags->min_width - width_change;
		else
			flags->pad_char = ' ';
	}
}

static int	print_aligned(int nbr, int pad_count, t_flags *flags)
{
	int	char_count;

	char_count = 0;
	if (flags->left_align)
	{
		char_count += print_number_with_precision(nbr, flags);
		char_count += print_repeat(flags->pad_char, pad_count);
	}
	else
	{
		char_count += print_repeat(flags->pad_char, pad_count);
		char_count += print_number_with_precision(nbr, flags);
	}
	return (char_count);
}

int	print_nbr(int nbr, t_flags *flags)
{
	int	num_len;
	int	precision_count;
	int	pad_count;
	int	char_count;
	int	width_change;

	width_change = min((nbr < 0) + flags->signed_form + flags->space_sign, 1);
	num_len = count_num_len(nbr);
	if (nbr == 0 && flags->precision == 0)
		num_len = 0;
	update_flags(nbr, flags);
	precision_count = flags->precision - num_len;
	precision_count = max(precision_count, 0);
	width_change = num_len + width_change + precision_count;
	pad_count = flags->min_width - width_change;
	pad_count = max(pad_count, 0);
	char_count = print_aligned(nbr, pad_count, flags);
	if (char_count != width_change + pad_count)
		char_count = -1;
	return (char_count);
}
