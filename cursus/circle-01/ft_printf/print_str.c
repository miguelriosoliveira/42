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

static int	print_padded(char *str, char *padding, int is_left_align)
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

int	print_str(char *str, t_flags *flags)
{
	size_t	char_count;
	char	*pad;
	char	*copy;
	char	*substr;

	if (!str)
		str = "(null)";
	copy = ft_strdup(str);
	if (!copy)
		return (-1);
	substr = ft_substr(copy, 0, flags->precision);
	free(copy);
	if (!substr)
		return (-1);
	copy = substr;
	pad = create_padding(flags->min_width - ft_strlen(copy), flags->pad_char);
	if (!pad)
	{
		free(copy);
		return (-1);
	}
	char_count = print_padded(copy, pad, flags->left_align);
	free(pad);
	free(copy);
	return (char_count);
}
