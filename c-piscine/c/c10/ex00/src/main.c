/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
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
		ft_putstr_error("File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr_error("Too many arguments.\n");
		return (1);
	}
	failed_reading_file = ft_display_file(argv[1]);
	if (failed_reading_file)
	{
		ft_putstr_error("Cannot read file.\n");
		return (1);
	}
	return (0);
}
