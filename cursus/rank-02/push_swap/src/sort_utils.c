/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:18:59 by mrios-es          #+#    #+#             */
/*   Updated: 2025/02/16 16:27:36 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find biggest element in `stack_b` smaller than `number`.
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

int	calculate_steps(int index_a, int index_b, int sa_size, int sb_size)
{
	if (index_a <= sa_size / 2)
	{
		if (index_b <= sb_size / 2)
			return (max(index_a, index_b));
		return (index_a + sb_size - index_b);
	}
	if (index_b <= sb_size / 2)
		return (sa_size - index_a + index_b);
	return (max(sa_size - index_a, sb_size - index_b));
}

void	update_cheapest(int i, int steps, int *min_steps, int *cheapest_index)
{
	if (steps < *min_steps)
	{
		*min_steps = steps;
		*cheapest_index = i;
	}
}

int	calculate_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*curr;
	int		min_steps;
	int		index_b;
	int		i;
	int		cheapest_index;

	curr = stack_a->stack;
	min_steps = INT_MAX;
	i = 0;
	while (curr)
	{
		index_b = get_right_position(
				(int)(unsigned long)curr->content, stack_b);
		update_cheapest(i,
			calculate_steps(i, index_b, stack_a->size, stack_b->size),
			&min_steps, &cheapest_index);
		i++;
		curr = curr->next;
	}
	return (cheapest_index);
}
