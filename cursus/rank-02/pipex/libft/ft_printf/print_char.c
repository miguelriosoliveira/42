/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:59:25 by mrios-es          #+#    #+#             */
/*   Updated: 2023/10/11 23:59:25 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, t_flags *flags)
{
	size_t	char_count;
	char	*padding;

	padding = create_padding(flags->min_width - 1, flags->pad_char);
	if (!padding)
		return (-1);
	char_count = 0;
	if (!flags->left_align)
		char_count += ft_putstr_fd(padding, 1);
	char_count += ft_putchar_fd(c, 1);
	if (flags->left_align)
		char_count += ft_putstr_fd(padding, 1);
	if (char_count != ft_strlen(padding) + 1)
		char_count = -1;
	free(padding);
	return (char_count);
}
