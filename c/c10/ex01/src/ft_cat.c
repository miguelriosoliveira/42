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

int	ft_cat(char *filename)
{
	int		file_descriptor;
	char	buffer[1];

	if (filename[0] == '-')
	{
		file_descriptor = 0;
		while (read(file_descriptor, buffer, sizeof(buffer)) > 0)
			ft_putstr(buffer);
		return (0);
	}
	return (ft_display_file(filename));
}
