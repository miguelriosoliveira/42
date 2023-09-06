/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 22:25:35 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/06 22:25:35 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	if (!begin_list)
		return (begin_list);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

/*
void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	elem->next = *begin_list;
	*begin_list = elem;
}

#include <stdio.h>
int main() {
	t_list *elem = ft_create_elem("usopp");
	ft_list_push_front(&elem, "captain");
	ft_list_push_front(&elem, "great");
	t_list *last = ft_list_last(elem);
	printf("last element is: \"%s\"\n", (char*)last->data);

	elem = NULL;
	last = ft_list_last(elem);
	printf("last element is: \"%s\"\n", (char*)last); // should be null

	return 0;
}
*/
