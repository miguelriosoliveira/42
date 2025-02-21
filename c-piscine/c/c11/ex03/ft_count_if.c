/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:38:50 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/05 23:38:50 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < length)
	{
		if (f(tab[i]))
			counter++;
		i++;
	}
	return (counter);
}

/*
#include <string.h>
int	check42(char* str) {
	return strcmp(str, "42") == 0;
}

#include <stdlib.h>
#include <stdio.h>
int main() {
	char **tab = malloc(6 * sizeof(char*));
	tab[0] = "1";
	tab[1] = "2";
	tab[2] = "42";
	tab[3] = "42";
	tab[4] = "5";
	printf("how many 42s are in tab? %d\n", ft_count_if(tab, 5, &check42));

	tab[2] = "3";
	printf("how many 42s are in tab? %d\n", ft_count_if(tab, 5, &check42));

	tab[3] = "4";
	printf("how many 42s are in tab? %d\n", ft_count_if(tab, 5, &check42));
}
*/
