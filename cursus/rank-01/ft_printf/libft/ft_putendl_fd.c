/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:05:11 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/13 19:05:11 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	char_count;
	int	n_written;

	char_count = 0;
	n_written = 0;
	n_written = ft_putstr_fd(s, fd);
	if (n_written == -1)
		return (-1);
	char_count += n_written;
	n_written = ft_putchar_fd('\n', fd);
	if (n_written == -1)
		return (-1);
	char_count += n_written;
	return (char_count);
}
