/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:59:48 by mrios-es          #+#    #+#             */
/*   Updated: 2023/09/24 21:59:48 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_curr;
	t_list	*curr;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = f(lst);
	if (!new_lst)
		return (NULL);
	new_curr = new_lst;
	curr = lst;
	while (curr)
	{
		new_curr = f(curr);
		curr = curr->next;
		new_curr = new_curr->next;
	}
	return (new_lst);
}
