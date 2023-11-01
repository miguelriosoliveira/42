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

static int	print_zeropad(char *num_str, char *pad, t_flags *flags)
{
	size_t	char_count;

	char_count = print_padded(num_str + 2, pad, flags->left_align);
	if (char_count != ft_strlen(num_str) + ft_strlen(pad))
		return (-1);
	return (char_count);
}

int	print_hex(unsigned long nbr, int is_upper, t_flags *flags)
{
	int	num_len;
	int	precision_count;
	int	pad_count;
	int	char_count;
	int	width_change;

	num_len = count_unum_len(nbr);
	if (nbr == 0 && flags->precision == 0)
		num_len = 0;
	update_flags(flags);
	precision_count = flags->precision - num_len;
	precision_count = max(precision_count, 0);
	width_change = num_len + precision_count;
	pad_count = flags->min_width - width_change;
	pad_count = max(pad_count, 0);
	char_count = print_aligned(nbr, pad_count, flags);
	if (char_count != width_change + pad_count)
		char_count = -1;
	return (char_count);
}
