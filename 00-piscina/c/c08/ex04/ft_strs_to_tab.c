/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:49:36 by mrios-es          #+#    #+#             */
/*   Updated: 2023/08/12 13:49:36 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*copy;

	src_len = ft_strlen(src);
	copy = malloc(src_len * sizeof(char));
	ft_strcpy(copy, src);
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	char		*str;
	t_stock_str	*stocks;
	t_stock_str	*current_stock;

	stocks = malloc((ac + 1) * sizeof(t_stock_str));
	if (!stocks)
		return (NULL);
	stocks[ac].size = 0;
	stocks[ac].str = 0;
	stocks[ac].copy = 0;
	i = 0;
	while (i < ac)
	{
		str = av[i];
		current_stock = &stocks[i];
		current_stock->size = ft_strlen(str);
		current_stock->str = str;
		current_stock->copy = ft_strdup(str);
		i++;
	}
	return (stocks);
}

/*
#include <stdio.h>
int main(int argc, char **argv) {
	t_stock_str *stocks = ft_strs_to_tab(argc, argv);
	stocks[0].copy[0] = '#'; // change the firsgt letter of the program's name

	t_stock_str stock;
	int i = 0;
	while (stocks[i].str)
	{
		stock = stocks[i];
		printf("[%d] size: %d\n", i, stock.size);
		printf("[%d] str:  \"%s\"\n", i, stock.str);
		printf("[%d] copy: \"%s\"\n\n", i, stock.copy);
		i++;
	}

	return 0;
}
*/
