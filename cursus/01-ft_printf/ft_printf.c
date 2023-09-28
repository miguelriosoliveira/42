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

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		char_count;
	int		i;
	char	c;
	char	*s;
	void	*p;

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
				c = va_arg(args, int);
				ft_putchar_fd(c, 1);
			}
			if (format[i] == 's')
			{
				s = va_arg(args, char *);
				ft_putstr_fd(s, 1);
				char_count += ft_strlen(s) - 1;
			}
			if (format[i] == 'p')
			{
				p = va_arg(args, void *);
				ft_putstr_fd(p, 1);
				char_count += ft_strlen(s) - 1;
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
