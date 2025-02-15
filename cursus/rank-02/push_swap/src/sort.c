/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:35:02 by mrios-es          #+#    #+#             */
/*   Updated: 2025/02/15 22:35:16 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
123 - none
132 - rra - 213 - sa - 123
213 - sa  - 123
231 - rra - 123
312 - ra  - 123
321 - sa  - 231 - rra - 123
*/
void	sort_3(t_stack *stack_a)
{
	int	min;
	int	max;
	int	first;
	int	second;
	int	third;

	min = min_value(stack_a);
	max = max_value(stack_a);
	first = (int)(unsigned long)stack_a->stack->content;
	second = (int)(unsigned long)stack_a->stack->next->content;
	third = (int)(unsigned long)stack_a->stack->next->next->content;
	if (first == min && second == max)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (second == min && third == max)
		sa(stack_a);
	else if (second == max && third == min)
		rra(stack_a);
	else if (first == max && second == min)
		ra(stack_a);
	else if (first == max && third == min)
		return (sa(stack_a), rra(stack_a));
}

/**
 * Find biggest element in `stack_b` smaller than `number`.
 */
int	get_right_position(int number, t_stack *stack_b)
{
	t_list	*curr;
	int		i;
	int		max_b;
	int		max_b_index;
	int		content;

	i = 0;
	max_b = INT_MIN;
	max_b_index = -1;
	curr = stack_b->stack;
	while (curr)
	{
		content = (int)(unsigned long)curr->content;
		if (content < number && content > max_b)
		{
			max_b = content;
			max_b_index = i;
		}
		i++;
		curr = curr->next;
	}
	if (max_b_index >= 0)
		return (max_b_index);
	return (get_index(max_value(stack_b), stack_b));
}

void	execute_steps(int index, int number, t_stack *stack_a, t_stack *stack_b)
{
	int	index_b;

	index_b = get_right_position(number, stack_b);
	if (index > stack_a->size / 2)
		index = -1 * (stack_a->size - index);
	if (index_b > stack_b->size / 2)
		index_b = -1 * (stack_b->size - index_b);
	if (index > 0 && index_b > 0)
	{
		while (index && index_b)
		{
			rr(stack_a, stack_b);
			index--;
			index_b--;
		}
	}
	else if (index < 0 && index_b < 0)
	{
		while (index && index_b)
		{
			rrr(stack_a, stack_b);
			index++;
			index_b++;
		}
	}
	if (index >= 0)
		while (index--)
			ra(stack_a);
	else
		while (index++)
			rra(stack_a);
	if (index_b >= 0)
		while (index_b--)
			rb(stack_b);
	else
		while (index_b++)
			rrb(stack_b);
	pb(stack_a, stack_b);
}

int	insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*curr;
	int		steps;
	int		i;
	int		min_steps;
	int		cheapest;
	int		cheapest_index;
	int		index_b;

	while (stack_a->size > 3 && !is_sorted(stack_a))
	{
		curr = stack_a->stack;
		min_steps = INT_MAX;
		i = 0;
		while (curr)
		{
			index_b = get_right_position(
					(int)(unsigned long)curr->content, stack_b);
			if (i <= stack_a->size / 2)
			{
				if (index_b <= stack_b->size / 2)
					steps = max(i, index_b);
				else
					steps = i + stack_b->size - index_b;
			}
			else if (index_b <= stack_b->size / 2)
				steps = stack_a->size - i + index_b;
			else
				steps = max(stack_a->size - i, stack_b->size - index_b);
			if (steps < min_steps)
			{
				min_steps = steps;
				cheapest = (int)(unsigned long)curr->content;
				cheapest_index = i;
			}
			i++;
			curr = curr->next;
		}
		execute_steps(cheapest_index, cheapest, stack_a, stack_b);
	}
	return (EXIT_SUCCESS);
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

void	push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	index;

	while (stack_b->stack)
	{
		index = find_smallest_bigger_pos(
				(int)(unsigned long)stack_b->stack->content, stack_a);
		if (index <= stack_a->size / 2)
			while (index--)
				ra(stack_a);
		else
			while (index++ < stack_a->size)
				rra(stack_a);
		pa(stack_a, stack_b);
	}
}

void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_elem_index;

	if (stack_a->size > 3 && !is_sorted(stack_a))
		pb(stack_a, stack_b);
	if (stack_a->size > 3 && !is_sorted(stack_a))
		pb(stack_a, stack_b);
	insertion_sort(stack_a, stack_b);
	sort_3(stack_a);
	push_back_to_a(stack_a, stack_b);
	min_elem_index = get_index(min_value(stack_a), stack_a);
	if (min_elem_index <= stack_a->size)
		while (min_elem_index--)
			ra(stack_a);
	else
		while (min_elem_index++ < stack_a->size)
			rra(stack_a);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
		sa(stack_a);
	turk_sort(stack_a, stack_b);
}
