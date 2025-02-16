/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:26:21 by mrios-es          #+#    #+#             */
/*   Updated: 2025/02/16 16:26:58 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_ab(int index_a, int index_b, t_stack *sa, t_stack *sb)
{
	int	rotate_count;

	if (index_a <= sa->size / 2 && index_b <= sb->size / 2)
	{
		rotate_count = min(index_a, index_b);
		while (rotate_count--)
			rr(sa, sb);
		return (min(index_a, index_b));
	}
	if (index_a > sa->size / 2 && index_b > sb->size / 2)
	{
		index_a = sa->size - index_a;
		index_b = sb->size - index_b;
		rotate_count = min(index_a, index_b);
		while (rotate_count--)
			rrr(sa, sb);
		return (-1 * min(index_a, index_b));
	}
	return (0);
}

void	rotate_a(int index, t_stack *stack_a)
{
	if (index <= stack_a->size / 2)
		while (index--)
			ra(stack_a);
	else
		while (index++ < stack_a->size)
			rra(stack_a);
}

void	rotate_b(int index, t_stack *stack_b)
{
	if (index <= stack_b->size / 2)
		while (index--)
			rb(stack_b);
	else
		while (index++ < stack_b->size)
			rrb(stack_b);
}

void	execute_steps(int index_a, int index_b, t_stack *sa, t_stack *sb)
{
	int	rotate_ab_count;

	rotate_ab_count = rotate_ab(index_a, index_b, sa, sb);
	index_a -= rotate_ab_count;
	index_b -= rotate_ab_count;
	rotate_a(index_a, sa);
	rotate_b(index_b, sb);
	pb(sa, sb);
}

int	find_smallest_bigger_pos(int number, t_stack *stack)
{
	int		i;
	int		index;
	int		min_elem;
	t_list	*curr;

	i = 0;
	curr = stack->stack;
	min_elem = INT_MAX;
	index = -1;
	while (curr)
	{
		if ((int)(unsigned long)curr->content > number
			&& (int)(unsigned long)curr->content < min_elem)
		{
			min_elem = (int)(unsigned long)curr->content;
			index = i;
		}
		i++;
		curr = curr->next;
	}
	if (index >= 0)
		return (index);
	return (get_index(min_value(stack), stack));
}
