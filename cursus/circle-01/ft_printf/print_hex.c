/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:03:36 by mrios-es          #+#    #+#             */
/*   Updated: 2023/11/01 15:03:36 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex_len(unsigned int nbr)
{
	return (count_base_len(nbr, HEX_BASE_LOWER));
}

static int	print_on_precision(unsigned long nbr, int is_upper, t_flags *flags)
{
	int	char_count;
	int	num_len;
	int	pad_count;

	char_count = 0;
	if (nbr == 0 && flags->pad_char != '0' && flags->precision == 0)
		return (char_count);
	num_len = count_hex_len(nbr);
	if (nbr != 0 && flags->hex_form)
	{
		if (is_upper)
			char_count += ft_putstr_fd("0X", 1);
		else
			char_count += ft_putstr_fd("0x", 1);
	}
	pad_count = flags->precision - num_len;
	pad_count = max(pad_count, 0);
	char_count += print_repeat('0', pad_count);
	if (is_upper)
		char_count += ft_putnbr_base(nbr, HEX_BASE_UPPER);
	else
		char_count += ft_putnbr_base(nbr, HEX_BASE_LOWER);
	return (char_count);
}

static void	update_flags(unsigned long nbr, t_flags *flags)
{
	if (flags->pad_char == '0')
	{
		if (flags->precision < 0)
		{
			flags->precision = flags->min_width;
			if (nbr != 0 && flags->hex_form)
				flags->precision -= 2;
		}
		else
			flags->pad_char = ' ';
	}
}

static int	print_aligned(
	unsigned int nbr,
	int pad_count,
	int is_upper,
	t_flags *flags
)
{
	int	char_count;

	char_count = 0;
	if (flags->left_align)
	{
		char_count += print_on_precision(nbr, is_upper, flags);
		char_count += print_repeat(flags->pad_char, pad_count);
	}
	else
	{
		char_count += print_repeat(flags->pad_char, pad_count);
		char_count += print_on_precision(nbr, is_upper, flags);
	}
	return (char_count);
}

int	print_hex(unsigned long nbr, int is_upper, t_flags *flags)
{
	int	num_len;
	int	precision_count;
	int	pad_count;
	int	char_count;

	num_len = count_hex_len(nbr);
	if (nbr == 0 && flags->precision == 0)
		num_len = 0;
	update_flags(nbr, flags);
	precision_count = flags->precision - num_len;
	precision_count = max(precision_count, 0);
	if (nbr != 0 && flags->hex_form)
		num_len += 2;
	pad_count = flags->min_width - num_len - precision_count;
	pad_count = max(pad_count, 0);
	char_count = print_aligned(nbr, pad_count, is_upper, flags);
	if (char_count != num_len + precision_count + pad_count)
		char_count = -1;
	return (char_count);
}
