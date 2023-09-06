/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 22:19:22 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/06 22:19:22 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
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
	printf("list size: %d\n", ft_list_size(elem));

	elem = NULL;
	printf("list size: %d\n", ft_list_size(elem));

	return 0;
}
*/
