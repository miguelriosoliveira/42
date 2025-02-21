/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 22:01:22 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/06 22:01:22 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	elem->next = *begin_list;
	*begin_list = elem;
}

/*
#include <stdio.h>
void print_list(t_list *begin_list) {
	if (!begin_list)
	{
		printf("\"%s\"\n", (char *)begin_list);
		return ;
	}

	t_list *current_elem = begin_list;

	printf("\"%s\"", (char *)current_elem->data);
	current_elem = current_elem->next;
	while (current_elem) {
		printf(" -> \"%s\"", (char *)current_elem->data);
		current_elem = current_elem->next;
	}

	printf("\n");
}

int main() {
	t_list *elem = ft_create_elem("usopp");
	ft_list_push_front(&elem, "captain");
	ft_list_push_front(&elem, "great");
	print_list(elem);

	elem = NULL;
	ft_list_push_front(&elem, "pirates");
	ft_list_push_front(&elem, "of");
	ft_list_push_front(&elem, "king");
	print_list(elem);

	return 0;
}
*/
