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

int	main(int argc, char **argv)
{
	int	failed_reading_file;

	if (argc < 2)
	{
		ft_putstr("File name missing.\n");
		return (0);
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (0);
	}
	failed_reading_file = ft_display_file(argv[1]);
	if (failed_reading_file)
	{
		ft_putstr("Cannot read file.\n");
		return (0);
	}
	return (0);
}
