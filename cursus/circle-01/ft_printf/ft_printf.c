/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:45:32 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/27 23:45:32 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_formatted(char format, va_list *args, t_flags *flags)
{
	if (format == 'c')
		return (print_char(va_arg(*args, int), flags));
	if (format == 's')
		return (print_str(va_arg(*args, char *), flags));
	if (format == 'p')
		return (print_ptr(va_arg(*args, void *), flags));
	if (format == 'd' || format == 'i')
		return (print_nbr(va_arg(*args, int), flags));
	if (format == 'u')
		return (print_unbr(va_arg(*args, unsigned int), flags));
	if (format == 'x')
		return (print_hex(va_arg(*args, unsigned int), 0, flags));
	if (format == 'X')
		return (print_hex(va_arg(*args, unsigned int), 1, flags));
	if (format == '%')
		return (print_char('%', flags));
	return (0);
}

static int	parse_print_unit(const char *format, int *i, va_list *args)
{
	int		char_count;
	t_flags	*flags;

	flags = read_flags(format, i);
	if (!flags)
		return (-1);
	char_count = print_formatted(format[*i], args, flags);
	free(flags);
	return (char_count);
}

static int	parse_print(const char *format, va_list	*args)
{
	int		i;
	int		n_written;
	int		char_count;

	i = 0;
	char_count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			n_written = parse_print_unit(format, &i, args);
		}
		else
			n_written = ft_putchar_fd(format[i], 1);
		if (n_written == -1)
			return (-1);
		char_count += n_written;
		i++;
	}
	return (char_count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		char_count;

	va_start(args, format);
	char_count = parse_print(format, &args);
	va_end(args);
	return (char_count);
}
