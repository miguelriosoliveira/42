/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:47:31 by mrios-es          #+#    #+#             */
/*   Updated: 2023/10/24 23:10:36 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_zeropad(char *join, char *pad, t_flags *flags)
{
	size_t	char_count;

	char_count = ft_putstr_fd("0x", 1);
	char_count += print_padded(join + 2, pad, flags->left_align);
	if (char_count != ft_strlen(join) + ft_strlen(pad))
		return (-1);
	return (char_count);
}

int	print_ptr(void *ptr, t_flags *flags)
{
	char	*num_str;
	char	*pad;
	char	*join;
	size_t	char_count;

	num_str = ft_uitoa((unsigned long)ptr, HEX_BASE_LOWER);
	if (!num_str)
		return (-1);
	join = ft_strjoin("0x", num_str);
	free(num_str);
	if (!join)
		return (-1);
	pad = create_padding(flags->min_width - ft_strlen(join), flags->pad_char);
	if (!pad)
	{
		free(join);
		return (-1);
	}
	if (flags->pad_char == '0')
		return (print_zeropad(join, pad, flags));
	char_count = print_padded(join, pad, flags->left_align);
	free(pad);
	free(join);
	return (char_count);
}
