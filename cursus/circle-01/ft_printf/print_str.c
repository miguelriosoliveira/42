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
