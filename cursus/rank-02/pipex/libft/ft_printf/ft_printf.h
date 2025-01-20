/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:46:01 by mrios-es          #+#    #+#             */
/*   Updated: 2024/08/22 22:48:21 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

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
int		ft_putnbr_base(unsigned long nbr, char *base);
char	*ft_uitoa(unsigned long n, char *base);
int		print_char(char c, t_flags *flags);
int		print_hex(unsigned long nbr, int is_upper, t_flags *flags);
int		print_nbr(int nbr, t_flags *flags);
int		print_unbr(unsigned int nbr, t_flags *flags);
int		print_ptr(void *ptr, t_flags *flags);
int		print_str(char *str, t_flags *flags);
char	*create_padding(int size, char c);
int		print_padded(char *str, char *padding, int is_left_align);
int		print_repeat(char c, int times);
int		count_num_len(int nbr);
int		count_unum_len(unsigned int nbr);
int		count_base_len(unsigned int nbr, char *base);
int		min(int a, int b);
int		max(int a, int b);

#endif
