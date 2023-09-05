/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:19:51 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/05 23:19:51 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
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
	tab[2] = "3";
	tab[3] = "42";
	tab[4] = "5";
	tab[5] = NULL;
	int is42 = ft_any(tab, &check42);
	printf("tab has at least one 42? %s\n", is42 ? "YES" : "NO");

	tab[3] = "4";
	is42 = ft_any(tab, &check42);
	printf("tab has at least one 42? %s\n", is42 ? "YES" : "NO");
}
*/
