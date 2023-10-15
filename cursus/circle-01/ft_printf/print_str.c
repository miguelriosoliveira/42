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
	size_t	str_len;
	char	*padding;
	char	*copy;
	char	*substr;

	if (!str)
		str = "(null)";
	copy = ft_strdup(str);
	if (flags->precision >= 0)
	{
		substr = ft_substr(copy, 0, flags->precision);
		free(copy);
		copy = substr;
	}
	str_len = ft_strlen(copy);
	padding = create_padding(flags->min_width - str_len, flags->pad_char);
	if (!padding)
		return (-1);
	char_count = print_padded(copy, padding, flags->left_align);
	free(padding);
	free(copy);
	return (char_count);
}
