/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:49:52 by mrios-es          #+#    #+#             */
/*   Updated: 2023/10/12 16:49:52 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// #include <stdio.h>
// #include <string.h>

/**
 * %s is affected by:
 * - left alignment
 * - zero-padding
 * - min width
 * - precision
*/
int	print_str(char *str, t_flags *flags)
{
	size_t	char_count;
	size_t	str_len;
	char	*padding;
	char	*substr;

	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	padding = create_padding(flags->min_width - str_len, flags->pad_char);
	if (!padding)
		return (-1);
	char_count = 0;
	if (!flags->left_align)
		char_count += ft_putstr_fd(padding, 1);
	if (flags->precision)
	{
		substr = ft_substr(str, 0, flags->precision);
		str_len = ft_strlen(substr);
		char_count += ft_putstr_fd(substr, 1);
		free(substr);
	}
	else
		char_count += ft_putstr_fd(str, 1);
	if (flags->left_align)
		char_count += ft_putstr_fd(padding, 1);
	if (char_count != ft_strlen(padding) + str_len)
		char_count = -1;
	free(padding);
	return (char_count);
}
