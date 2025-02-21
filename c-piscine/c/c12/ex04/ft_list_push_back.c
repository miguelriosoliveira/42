/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 22:33:40 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/06 22:33:40 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_elem;
	t_list	*current;

	new_elem = ft_create_elem(data);
	current = *begin_list;
	if (!current)
	{
		*begin_list = new_elem;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = new_elem;
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
	t_list *elem = ft_create_elem("great");
	ft_list_push_back(&elem, "captain");
	ft_list_push_back(&elem, "usopp");
	print_list(elem);

	elem = NULL;
	ft_list_push_back(&elem, "king");
	ft_list_push_back(&elem, "of");
	ft_list_push_back(&elem, "pirates");
	print_list(elem);

	return 0;
}
*/
