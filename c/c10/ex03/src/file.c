/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:19:57 by mrios-es          #+#    #+#             */
/*   Updated: 2023/08/17 22:19:57 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_file(char *filename)
{
	int		file_descriptor;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
	{
		ft_putstr_error("ft_hexdump: ");
		ft_putstr_error(filename);
		ft_putstr_error(": ");
		ft_putstr_error(strerror(errno));
		ft_putstr_error("\n");
		return (0);
	}
	close(file_descriptor);
	return (1);
}
