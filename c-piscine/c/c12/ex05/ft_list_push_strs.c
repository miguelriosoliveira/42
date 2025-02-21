/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 23:12:19 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/06 23:12:19 by mrios-es         ###   ########.fr       */
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

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*new_list;
	int		i;

	new_list = 0;
	i = 0;
	while (i < size)
	{
		ft_list_push_back(&new_list, strs[i]);
		i++;
	}
	return (new_list);
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
	char *strs[] = {"great", "captain", "usopp"};
	t_list *elem = ft_list_push_strs(3, strs);
	print_list(elem);

	char **strs2 = NULL;
	elem = ft_list_push_strs(0, strs2);
	print_list(elem);

	return 0;
}
*/
