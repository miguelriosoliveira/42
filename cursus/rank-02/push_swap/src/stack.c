/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:33:08 by mrios-es          #+#    #+#             */
/*   Updated: 2025/02/15 22:34:14 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int number, t_stack *stack)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = stack->stack;
	while (curr)
	{
		if ((int)(unsigned long)curr->content == number)
			return (i);
		i++;
		curr = curr->next;
	}
	return (-1);
}

int	get_value(int index, t_stack *stack)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = stack->stack;
	while (i != index)
	{
		i++;
		curr = curr->next;
	}
	return ((int)(unsigned long)curr->content);
}

int	min_value(t_stack *stack)
{
	int		min;
	int		content;
	t_list	*curr;

	curr = stack->stack;
	min = INT_MAX;
	while (curr)
	{
		content = (int)(unsigned long)curr->content;
		if (content < min)
			min = content;
		curr = curr->next;
	}
	return (min);
}

int	max_value(t_stack *stack)
{
	int		max;
	int		content;
	t_list	*curr;

	curr = stack->stack;
	max = INT_MIN;
	while (curr)
	{
		content = (int)(unsigned long)curr->content;
		if (content > max)
			max = content;
		curr = curr->next;
	}
	return (max);
}
