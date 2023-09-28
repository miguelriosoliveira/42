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

int	find_index(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	to_base(char *str, char *base, int base_size)
{
	int		i;
	long	result;
	int		sign;
	int		pos_in_base;

	i = 0;
	sign = 1;
	while (str[i] && !(str[i] > 32 && str[i] <= 126))
		i++;
	while (str[i] && find_index(str[i], "+-") >= 0)
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	pos_in_base = find_index(str[i], base);
	while (str[i] && pos_in_base >= 0)
	{
		result = result * base_size + pos_in_base;
		i++;
		pos_in_base = find_index(str[i], base);
	}
	return (sign * result);
}

static void	print_address(void *ptr)
{
	unsigned long	address;
	char			*hex_base;
	char			buffer[16];
	int				i;
	int				size;

	address = (unsigned long)ptr;
	hex_base = "0123456789abcdef";
	size = 8;
	i = size;
	while (i >= 0)
	{
		buffer[i] = hex_base[address % 16];
		address /= 16;
		i--;
	}
	write(1, "0x", 2);
	write(1, buffer, size + 1);
}

static int	count_chars(unsigned int nb)
{
	long	nbr;
	int		count;

	nbr = nb;
	count = 1;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

static void	ft_putnbr_uint(unsigned int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}

#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				char_count;
	int				i;
	int				int_param;
	unsigned int	uint_param;
	char			*string_param;
	void			*pointer_param;

	va_start(args, format);
	char_count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				int_param = va_arg(args, int);
				ft_putchar_fd(int_param, 1);
			}
			else if (format[i] == 's')
			{
				string_param = va_arg(args, char *);
				ft_putstr_fd(string_param, 1);
				char_count += ft_strlen(string_param) - 1;
			}
			else if (format[i] == 'p')
			{
				pointer_param = va_arg(args, void *);
				print_address(pointer_param);
				char_count += 10;
			}
			else if (ft_strchr("di", format[i]))
			{
				int_param = va_arg(args, int);
				string_param = ft_itoa(int_param);
				ft_putstr_fd(string_param, 1);
				char_count += ft_strlen(string_param) - 1;
			}
			else if (format[i] == 'u')
			{
				uint_param = va_arg(args, unsigned int);
				ft_putnbr_uint(uint_param, 1);
				char_count += count_chars(uint_param) - 1;
			}
			else if (format[i] == 'x')
			{
				int_param = va_arg(args, int);

				printf("int_param: %d\n", int_param);

				string_param = ft_itoa(int_param);

				printf("string_param: \"%s\"\n", string_param);

				int_param = to_base(string_param, "0123456789abcdef", 16);

				printf("int_param: %d\n", int_param);

				string_param = ft_itoa(int_param);

				printf("string_param: \"%s\"\n", string_param);

				ft_putstr_fd(string_param, 1);
				char_count += ft_strlen(string_param) - 1;
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
