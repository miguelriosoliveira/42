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
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>

# define BLOCK_SIZE 128
# define LINE_SIZE 16

int		check_file(char *filename);
void	*ft_print_memory(void *addr, unsigned int size);
void	ft_hexdump(int filecount, char **filenames);
void	ft_putchar(char c);
void	ft_putchar_error(char c);
void	ft_putnbr_base(int nbr, char *base, int digits);
void	ft_putstr(char *str);
void	ft_putstr_error(char *str);
char	**ft_split(char *str, char *charset);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		includes(char c, char *str);

#endif
