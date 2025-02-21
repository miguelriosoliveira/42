/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:32:26 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/06 21:32:26 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_swap(char **a, char **b)
{
	char	*aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void	ft_sort_char_tab(char **tab, int size, int (*cmp)(char *, char *))
{
	int	swap_count;
	int	i;

	swap_count = 1;
	while (swap_count > 0)
	{
		swap_count = 0;
		i = 0;
		while (i < size - 1)
		{
			if (cmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap(&tab[i], &tab[i + 1]);
				swap_count++;
			}
			i++;
		}
	}
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	ft_sort_char_tab(tab, i, cmp);
}

/*
#include <stdio.h>
int	main() {
	char *tab[] = {
		"luffy",
		"zoro",
		"nami",
		"usopp",
		"sanji",
		"chopper",
		"robin",
		"franky",
		"brook",
		"jinbe",
		NULL,
	};

	printf("before: [ ");
	int	i = 0;
	while (tab[i] != NULL)
	{
		printf("%s ", tab[i]);
		i++;
	}
	printf("]");
	printf("\n");

	ft_advanced_sort_string_tab(tab, ft_strcmp);

	printf("after:  [ ");
	i = 0;
	while (tab[i] != NULL)
	{
		printf("%s ", tab[i]);
		i++;
	}
	printf("]");
	printf("\n");

	return (0);
}
*/
