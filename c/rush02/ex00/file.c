/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:11:00 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/18 20:11:02 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

int	walk_line(int file_descriptor)
{
	char	buffer[1];
	int		flag;
	int		success;

	flag = 0;
	success = 0;
	while (read(file_descriptor, buffer, sizeof(buffer)) > 0)
	{
		if (buffer[0] == ':')
		{
			flag = 1;
			continue ;
		}
		if (is_space(buffer[0]))
			continue ;
		if (flag == 1 && !is_space(buffer[0]) && buffer[0] != '\n')
		{
			ft_putchar(buffer[0]);
			success = 1;
		}
		else
			break ;
	}
	return (success);
}

void	get_number_name(char *number, char *file_name)
{
	int		file_descriptor;
	char	buffer[1];
	int		match_counter;

	file_descriptor = open(file_name, O_RDONLY);
	if (file_descriptor == -1)
	{
		print_dict_error();
		return ;
	}
	match_counter = 0;
	while (read(file_descriptor, buffer, sizeof(buffer)) > 0)
	{
		if (number[match_counter] == buffer[0])
		{
			match_counter++;
			if (match_counter == ft_strlen(number)
				&& walk_line(file_descriptor))
				return ;
		}
		else
			match_counter = 0;
	}
	close(file_descriptor);
}
