/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:46:11 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/22 15:46:13 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range_len;
	int	i;
	int	*range;

	range = NULL;
	if (min >= max)
		return (range);
	range_len = max - min + 1;
	range = malloc(range_len * sizeof(int));
	i = 0;
	while (i < range_len)
	{
		range[i] = i + min;
		i++;
	}
	return (range);
}

/*
#include <stdio.h>
int main() {
	int min;
	int max;
	int i;
	int *range;

	min = 0;
	max = 0;
	range = ft_range(min, max);
	printf("ft_range(%3i, %3i): %s", min, max, range == NULL ? "NULL" : "NOT NULL");
	printf("\n");

	min = 0;
	max = 5;
	range = ft_range(min, max);
	printf("ft_range(%3i, %3i):", min, max);
	i = 0;
	while (i < (max - min + 1))
	{
		printf(" %3i", range[i]);
		i++;
	}
	printf("\n");

	min = -5;
	max = 5;
	range = ft_range(min, max);
	printf("ft_range(%3i, %3i):", min, max);
	i = 0;
	while (i < (max - min + 1))
	{
		printf(" %3i", range[i]);
		i++;
	}
	printf("\n");

	min = -10;
	max = -5;
	range = ft_range(min, max);
	printf("ft_range(%3i, %3i):", min, max);
	i = 0;
	while (i < (max - min + 1))
	{
		printf(" %3i", range[i]);
		i++;
	}
	printf("\n");

	min = 5;
	max = 0;
	range = ft_range(min, max);
	printf("ft_range(%3i, %3i): %s", min, max, range == NULL ? "NULL" : "NOT NULL");
	printf("\n");
}
*/
