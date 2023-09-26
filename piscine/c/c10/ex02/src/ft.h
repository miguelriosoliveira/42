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

# define BLOCK_SIZE 1024

int		check_file(char *filename);
int		count_chars(char *filename);
int		calculate_start(char *filename, int reverse_start);
void	seek(int file_descriptor, int position);
void	ft_putchar(char c);
void	ft_putchar_error(char c);
void	ft_putstr(char *str);
void	ft_putstr_error(char *str);
char	**ft_split(char *str, char *charset);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_tail(int filecount, char **filenames, int bytes);
int		includes(char c, char *str);

#endif
