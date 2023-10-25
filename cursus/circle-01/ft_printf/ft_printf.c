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

// #include <stdio.h>
// void print_flags(t_flags *flags)
// {
// 	printf("flags {\n");
// 	printf("\tleft_align: %d\n", flags->left_align);
// 	printf("\tpad_char: '%c'\n", flags->pad_char);
// 	printf("\tprecision: %d\n", flags->precision);
// 	printf("\tmin_width: %d\n", flags->min_width);
// 	printf("\thex_form: %d\n", flags->hex_form);
// 	printf("\tspace_sign: %d\n", flags->space_sign);
// 	printf("\tsigned_form: %d\n", flags->signed_form);
// 	printf("}\n");
// }

static int	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned int	base_len;
	int				n_written;
	int				char_count;

	base_len = ft_strlen(base);
	n_written = 0;
	char_count = 0;
	if (nbr >= base_len)
	{
		n_written = ft_putnbr_base(nbr / base_len, base);
		if (n_written == -1)
			return (-1);
		char_count += n_written;
	}
	n_written = ft_putchar_fd(base[nbr % base_len], 1);
	if (n_written == -1)
		return (-1);
	char_count += n_written;
	return (char_count);
}

static int	print_formatted(char format, va_list *args, t_flags *flags)
{

	// print_flags(flags);

	if (format == 'c')
		return (print_char(va_arg(*args, int), flags));
	if (format == 's')
		return (print_str(va_arg(*args, char *), flags));
	if (format == 'p')
		return (print_ptr(va_arg(*args, void *), flags));
	if (format == 'd' || format == 'i')
		// return (ft_putnbr_fd(va_arg(*args, int), 1));
		return (print_nbr(va_arg(*args, int), flags));
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
	va_list	args;
	int		n_written;
	int		char_count;
	int		i;
	t_flags	*flags;

	va_start(args, format);
	n_written = 0;
	char_count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			flags = read_flags(format, &i);
			if (!flags)
				return (-1);
			n_written = print_formatted(format[i], &args, flags);
			free(flags);
		}
		else
			n_written = ft_putchar_fd(format[i], 1);
		if (n_written == -1)
			break ;
		char_count += n_written;
		i++;
	}
	va_end(args);
	if (n_written == -1)
		return (-1);
	return (char_count);
}
