/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 00:03:42 by mrios-es          #+#    #+#             */
/*   Updated: 2023/10/12 00:03:42 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_specifier(char c)
{
	return (ft_strchr("cspdiuxX%", c) != NULL);
}

static int	count_next_digits(const char *format)
{
	int	i;

	i = 0;
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

t_flags	*read_flags(const char *format, int *i)
{
	t_flags	*flags;

	flags = ft_calloc(1, sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->pad_char = ' ';
	flags->precision = -1;
	while (format[*i] && !is_specifier(format[*i]))
	{
		if (format[*i] == '-')
			flags->left_align = 1;
		else if (format[*i] == '0')
		{
			if (!flags->left_align)
				flags->pad_char = '0';
		}
		else if (format[*i] == '.')
		{
			*i += 1;
			if (!ft_isdigit(format[*i]))
			{
				flags->precision = 0;
				continue ;
			}
			flags->precision = ft_atoi(&format[*i]);
			*i += count_next_digits(&format[*i]) - 1;

		}
		else if (ft_isdigit(format[*i]))
		{
			flags->min_width = ft_atoi(&format[*i]);
			*i += count_next_digits(&format[*i]) - 1;
		}
		else if (format[*i] == '#')
			flags->hex_form = 1;
		else if (format[*i] == ' ' && !flags->signed_form)
			flags->space_sign = 1;
		else if (format[*i] == '+')
		{
			flags->signed_form = 1;
			flags->space_sign = 0;
		}
		*i += 1;
	}
	return (flags);
}
