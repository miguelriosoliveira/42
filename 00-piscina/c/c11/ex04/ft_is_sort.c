/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:49:34 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/05 23:49:34 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

/*
#include <string.h>
int	compare(int a, int b) {
	return a - b;
}

#include <stdlib.h>
#include <stdio.h>
int main() {
	int tab[] = {1, 2, 3, 4, 5};
	printf("is tab sorted? %s\n", ft_is_sort(tab, 5, &compare) ? "YES" : "NO");

	tab[2] = 0;
	printf("is tab sorted? %s\n", ft_is_sort(tab, 5, &compare) ? "YES" : "NO");

	tab[0] = 3;
	tab[1] = 3;
	tab[2] = 3;
	tab[3] = 3;
	tab[4] = 3;
	printf("is tab sorted? %s\n", ft_is_sort(tab, 5, &compare) ? "YES" : "NO");
}
*/
