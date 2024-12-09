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

static int	count_next_digits(const char *format)
{
	int	i;

	i = 0;
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

static void	setup_precision(const char *format, int *i, t_flags *flags)
{
	*i += 1;
	flags->precision = ft_atoi(&format[*i]);
	*i += count_next_digits(&format[*i]) - 1;
}

static void	setup_signed_form(t_flags *flags)
{
	flags->signed_form = 1;
	flags->space_sign = 0;
}

static void	build_flags(const char *format, int *i, t_flags *flags)
{
	while (format[*i] && ft_strchr("cspdiuxX%", format[*i]) == NULL)
	{
		if (format[*i] == '-')
			flags->left_align = 1;
		else if (format[*i] == '0')
		{
			if (!flags->left_align)
				flags->pad_char = '0';
		}
		else if (format[*i] == '.')
			setup_precision(format, i, flags);
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
			setup_signed_form(flags);
		*i += 1;
	}
}

t_flags	*read_flags(const char *format, int *i)
{
	t_flags	*flags;

	flags = ft_calloc(1, sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->pad_char = ' ';
	flags->precision = -1;
	build_flags(format, i, flags);
	return (flags);
}
