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
# include <string.h>
# include <sys/errno.h>

int		ft_cat(char *filename);
int		ft_display_file(char *filename);
void	ft_putchar(char c);
void	ft_putchar_error(char c);
void	ft_putstr(char *str);
void	ft_putstr_error(char *str);

#endif
