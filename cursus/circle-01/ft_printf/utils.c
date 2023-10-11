/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 00:23:55 by mrios-es          #+#    #+#             */
/*   Updated: 2023/10/12 00:25:00 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_padding(int size, char c)
{
	char	*padding;
	int		i;

	if (size <= 0)
		size = 0;
	padding = ft_calloc(size + 1, sizeof(char));
	if (!padding)
		return (NULL);
	i = 0;
	while (i < size)
	{
		padding[i] = c;
		i++;
	}
	return (padding);
}
