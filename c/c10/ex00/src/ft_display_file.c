/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:24:29 by mrios-es          #+#    #+#             */
/*   Updated: 2023/08/14 16:24:29 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_display_file(char *filename)
{
	int		file_descriptor;
	char	buffer[1];

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (1);
	while (read(file_descriptor, buffer, sizeof(buffer)) > 0)
		ft_putstr(buffer);
	close(file_descriptor);
	return (0);
}
