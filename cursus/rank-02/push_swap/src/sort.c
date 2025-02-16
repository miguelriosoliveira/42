/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:35:02 by mrios-es          #+#    #+#             */
/*   Updated: 2025/02/16 20:53:28 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	index_a;
	int	index_b;
	int	cheapest;

	while (stack_a->size > 3 && !is_sorted(stack_a))
	{
		index_a = calculate_cheapest(stack_a, stack_b);
		cheapest = get_value(index_a, stack_a);
		index_b = get_right_position(cheapest, stack_b);
		execute_steps(index_a, index_b, stack_a, stack_b);
	}
}

/*
123 - none
132 - rra - 213 - sa - 123
213 - sa  - 123
231 - rra - 123
312 - ra  - 123
321 - sa  - 231 - rra - 123
*/
static void	sort_3(t_stack *stack_a)
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
		return (rra(stack_a), sa(stack_a));
	if (second == min && third == max)
		return (sa(stack_a));
	if (second == max && third == min)
		return (rra(stack_a));
	if (first == max && second == min)
		return (ra(stack_a));
	if (first == max && third == min)
		return (sa(stack_a), rra(stack_a));
}

static void	push_back_to_a(t_stack *stack_a, t_stack *stack_b)
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

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_elem_index;

	if (is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
		sa(stack_a);
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
