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

int	get_filecount(int argc, char **argv)
{
	int	filecount;

	if (ft_strcmp(argv[1], "-c") == 0)
		filecount = argc - 3;
	else
		filecount = argc - 2;
	return (filecount);
}

char	**get_filenames(char **argv)
{
	char	**filenames;

	if (ft_strcmp(argv[1], "-c") == 0)
		filenames = &argv[3];
	else
		filenames = &argv[2];
	return (filenames);
}

int	get_bytes(char **argv)
{
	char	*bytes_str;
	char	**parts;

	if (ft_strcmp(argv[1], "-c") == 0)
		bytes_str = argv[2];
	else
	{
		parts = ft_split(argv[1], "-c");
		bytes_str = parts[0];
	}
	return (ft_atoi(bytes_str));
}

int	main(int argc, char **argv)
{
	int		filecount;
	char	**filenames;
	int		bytes;

	filecount = get_filecount(argc, argv);
	filenames = get_filenames(argv);
	bytes = get_bytes(argv);
	ft_tail(filecount, filenames, bytes);
	return (errno > 0);
}
