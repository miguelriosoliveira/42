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
	int	i;
	int	failed_reading_file;

	if (argc < 2)
		ft_cat("-");
	i = 1;
	while (i < argc)
	{
		failed_reading_file = ft_cat(argv[i]);
		if (failed_reading_file)
		{
			ft_putstr("Cannot read file: ");
			ft_putstr(argv[i]);
			ft_putstr("\n");
		}
		i++;
	}
	return (0);
}
