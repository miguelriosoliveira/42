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

static int	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned int	base_len;
	int				n_written;
	static int		char_count;

	base_len = ft_strlen(base);
	n_written = 0;
	char_count = 0;
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base);
	n_written = ft_putchar_fd(base[nbr % base_len], 1);
	if (n_written == -1)
		return (-1);
	char_count += n_written;
	return (char_count);
}

static int	ft_putptr(void *ptr)
{
	int	char_count;
	int	n_written;

	char_count = 0;
	n_written = 0;
	n_written = ft_putstr_fd("0x", 1);
	if (n_written == -1)
		return (-1);
	char_count += n_written;
	n_written = ft_putnbr_base((unsigned long)ptr, HEX_BASE_LOWER);
	if (n_written == -1)
		return (-1);
	char_count += n_written;
	return (char_count);
}

static int	print_formatted(char format, va_list *args)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(*args, int), 1));
	if (format == 's')
		return (ft_putstr_fd(va_arg(*args, char *), 1));
	if (format == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(*args, int), 1));
	if (format == 'u')
		return (ft_putnbr_fd(va_arg(*args, unsigned int), 1));
	if (format == 'x')
		return (ft_putnbr_base(va_arg(*args, unsigned int), HEX_BASE_LOWER));
	if (format == 'X')
		return (ft_putnbr_base(va_arg(*args, unsigned int), HEX_BASE_UPPER));
	if (format == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				char_count;
	int				i;

	if (!format)
		return (-1);
	va_start(args, format);
	char_count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			char_count += print_formatted(format[i], &args);
		}
		else
			char_count += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (char_count);
}
