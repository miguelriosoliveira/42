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
	t_list	*curr;
	void	*mapped_content;
	t_list	*mapped_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	curr = lst;
	while (curr)
	{
		mapped_content = f(curr->content);
		mapped_node = ft_lstnew(mapped_content);
		if (!mapped_node)
		{
			ft_lstclear(&new_lst, del);
			del(mapped_content);
			free(mapped_node);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, mapped_node);
		curr = curr->next;
	}
	return (new_lst);
}
