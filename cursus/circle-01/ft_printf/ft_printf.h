/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:46:01 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/27 23:46:01 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"

typedef struct s_flags
{
	int		left_align;
	char	pad_char;
	int		precision;
	int		min_width;
	int		hex_form;
	int		space_sign;
	int		signed_form;
}	t_flags;

int		ft_printf(const char *format, ...);
t_flags	*read_flags(const char *format, int *i);
int		print_char(char c, t_flags *flags);
int		print_nbr(int nbr, t_flags *flags);
int		print_ptr(void *ptr, t_flags *flags);
int		print_str(char *str, t_flags *flags);
char	*create_padding(int size, char c);
int		print_padded(char *str, char *padding, int is_left_align);

#endif
