/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:50:43 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/06 21:50:43 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

/*
#include <stdio.h>
int main() {
	t_list *elem = ft_create_elem("great captain usopp!");
	printf("data: \"%s\"\n", (char *)elem->data);
	printf("next: \"%s\"\n", (char *)elem->next);
	return 0;
}
*/
