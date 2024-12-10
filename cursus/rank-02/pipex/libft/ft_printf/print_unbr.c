/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:43:03 by mrios-es          #+#    #+#             */
/*   Updated: 2023/11/01 14:43:03 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_number_with_precision(unsigned long nbr, t_flags *flags)
{
	int	char_count;
	int	num_len;
	int	pad_count;

	char_count = 0;
	if (flags->signed_form)
		char_count += ft_putchar_fd('+', 1);
	else if (flags->space_sign)
		char_count += ft_putchar_fd(' ', 1);
	if (nbr == 0 && flags->pad_char != '0' && flags->precision == 0)
		return (char_count);
	num_len = count_unum_len(nbr);
	pad_count = max(flags->precision - num_len, 0);
	char_count += print_repeat('0', pad_count);
	char_count += ft_putnbr_fd(nbr, 1);
	return (char_count);
}

static void	update_flags(t_flags *flags)
{
	int	width_change;

	width_change = min(flags->signed_form + flags->space_sign, 1);
	if (flags->pad_char == '0')
	{
		if (flags->precision < 0)
			flags->precision = flags->min_width - width_change;
		else
			flags->pad_char = ' ';
	}
}

static int	print_aligned(unsigned int nbr, int pad_count, t_flags *flags)
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

int	print_unbr(unsigned int nbr, t_flags *flags)
{
	int	num_len;
	int	precision_count;
	int	pad_count;
	int	char_count;
	int	width_change;

	width_change = min(flags->signed_form + flags->space_sign, 1);
	num_len = count_unum_len(nbr);
	if (nbr == 0 && flags->precision == 0)
		num_len = 0;
	update_flags(flags);
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
