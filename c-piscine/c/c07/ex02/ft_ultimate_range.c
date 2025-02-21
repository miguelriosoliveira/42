/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:47:10 by mrios-es          #+#    #+#             */
/*   Updated: 2023/06/22 15:47:12 by mrios-es         ###   ########.fr       */
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

int	ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = ft_range(min, max - 1);
	if (!*range)
		return (-1);
	return (max - min);
}

/*
#include <stdio.h>
int main() {
	int min;
	int max;
	int i;
	int range_len;
	int *range;

	min = 0;
	max = 0;
	range_len = ft_ultimate_range(&range, min, max);
	printf("ft_ultimate_range(range, %3i, %3i)", min, max);
	printf(": %s (size: %i)", range == NULL ? "NULL" : "NOT NULL", range_len);
	printf("\n");

	min = 0;
	max = 5;
	range_len = ft_ultimate_range(&range, min, max);
	printf("ft_ultimate_range(range, %3i, %3i):", min, max);
	i = 0;
	while (i < (max - min + 1))
	{
		printf(" %3i", range[i]);
		i++;
	}
	printf(" (size: %i)", range_len);
	printf("\n");

	min = -5;
	max = 5;
	range_len = ft_ultimate_range(&range, min, max);
	printf("ft_ultimate_range(range, %3i, %3i):", min, max);
	i = 0;
	while (i < (max - min + 1))
	{
		printf(" %3i", range[i]);
		i++;
	}
	printf(" (size: %i)", range_len);
	printf("\n");

	min = -10;
	max = -5;
	range_len = ft_ultimate_range(&range, min, max);
	printf("ft_ultimate_range(range, %3i, %3i):", min, max);
	i = 0;
	while (i < (max - min + 1))
	{
		printf(" %3i", range[i]);
		i++;
	}
	printf(" (size: %i)", range_len);
	printf("\n");

	min = 5;
	max = 0;
	range_len = ft_ultimate_range(&range, min, max);
	printf("ft_ultimate_range(range, %3i, %3i)", min, max);
	printf(": %s (size: %i)", range == NULL ? "NULL" : "NOT NULL", range_len);
	printf("\n");

	min = 2147483647;
	max = 2147483647;
	range_len = ft_ultimate_range(&range, min, max);
	printf("ft_ultimate_range(range, %3i, %3i)", min, max);
	printf(": %s (size: %i)", range == NULL ? "NULL" : "NOT NULL", range_len);
	printf("\n");

	min = -2147483648;
	max = -2147483648;
	range_len = ft_ultimate_range(&range, min, max);
	printf("ft_ultimate_range(range, %3i, %3i)", min, max);
	printf(": %s (size: %i)", range == NULL ? "NULL" : "NOT NULL", range_len);
	printf("\n");
}
*/
