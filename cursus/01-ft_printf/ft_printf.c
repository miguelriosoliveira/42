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

static int	ft_putnbr_base(long nbr, char *base)
{
	int			base_len;
	static int	char_count;

	char_count = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbr = -nbr;
		char_count++;
	}
	base_len = ft_strlen(base);
	if (nbr >= base_len)
	{
		ft_putnbr_base(nbr / base_len, base);
		char_count++;
	}
	ft_putchar_fd(base[nbr % base_len], 1);
	return (char_count + 1);
}

static int	print_address(void *ptr)
{
	int		char_count;

	char_count = ft_putstr_fd("0x", 1);
	char_count += ft_putnbr_base((long)ptr, HEX_BASE_LOWER);
	return (char_count);
}

static int	ft_putnbr_uint_fd(unsigned int n, int fd)
{
	int			is_negative;
	static int	char_count;

	is_negative = 0;
	char_count = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		is_negative = 1;
	}
	if (n >= 10)
	{
		ft_putnbr_uint_fd(n / 10, fd);
		char_count++;
	}
	ft_putchar_fd(n % 10 + '0', fd);
	return (char_count + is_negative + 1);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				char_count;
	int				i;

	va_start(args, format);
	char_count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			char_count--;
			if (format[i] == 'c')
			{
				char_count += ft_putchar_fd(va_arg(args, int), 1);
			}
			else if (format[i] == 's')
			{
				char_count += ft_putstr_fd(va_arg(args, char *), 1);
			}
			else if (format[i] == 'p')
			{
				char_count += print_address(va_arg(args, void *));
			}
			else if (ft_strchr("di", format[i]))
			{
				char_count += ft_putnbr_fd(va_arg(args, int), 1);
			}
			else if (format[i] == 'u')
			{
				char_count += ft_putnbr_uint_fd(va_arg(args, unsigned int), 1);
			}
			else if (format[i] == 'x')
			{
				char_count += ft_putnbr_base(va_arg(args, int), HEX_BASE_LOWER);
			}
			else if (format[i] == 'X')
			{
				char_count += ft_putnbr_base(va_arg(args, int), HEX_BASE_UPPER);
			}
			else if (format[i] == '%')
			{
				char_count += ft_putchar_fd('%', 1);
			}
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
		char_count++;
	}
	va_end(args);
	return (char_count);
}
