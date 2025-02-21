/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:59:26 by mrios-es          #+#    #+#             */
/*   Updated: 2023/08/14 15:59:26 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

# define HEX_BASE "0123456789abcdef"

typedef int	(*t_operation)(int, int);

// do-op.c
void	doop(char *value1, char *op, char *value2);

// ft_atoi.c
int		ft_atoi(char *str);

// io.c
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

// math.c
int		sum(int a, int b);
int		subtract(int a, int b);
int		multiply(int a, int b);
int		divide(int a, int b);
int		modulo(int a, int b);

// string.c
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);

#endif
