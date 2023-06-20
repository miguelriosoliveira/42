/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:51:48 by mguardia          #+#    #+#             */
/*   Updated: 2023/06/18 15:33:48 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLIB_H
# define FTLIB_H
# define ARG_ERROR "Error\n"
# define DICT_ERROR "Dict Error\n"
# define DICT_FILE "numbers.dict"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int b);
int		is_multiple_1000(int count);
int		count_zeros(int count);
void	count_num_chars(int num, int count, int *total_char);
void	fill_count_chars(int count, char *str);
void	fill_num_chars(int num, int count, char *str);
void	print_dict_error(void);
int		is_space(char c);
int		walk_line(int file_descriptor);
void	get_number_name(char *number, char *file_name);

#endif
