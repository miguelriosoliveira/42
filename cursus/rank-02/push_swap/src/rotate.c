/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:35:31 by mrios-es          #+#    #+#             */
/*   Updated: 2025/02/02 20:25:11 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, int direction)
{
	t_list	*second;
	t_list	*pre_last;
	t_list	*last;

	last = ft_lstlast(stack);
	if (direction == UP)
	{
		second = stack->stack->next;
		last->next = stack->stack;
		stack->stack->next = NULL;
		stack->stack = second;
	}
	else
	{
		pre_last = stack->stack;
		while (pre_last->next->next)
			pre_last = pre_last->next;
		last->next = stack->stack;
		pre_last->next = NULL;
		stack->stack = last;
	}
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a, UP);
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b, UP);
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, UP);
	rotate(stack_b, UP);
	ft_printf("rr\n");
}
