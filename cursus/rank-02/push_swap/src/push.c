/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:20:15 by mrios-es          #+#    #+#             */
/*   Updated: 2025/02/03 22:23:25 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *stack_dst, t_stack *stack_src)
{
	t_list	*src_second;

	src_second = stack_src->stack->next;
	stack_src->stack->next = stack_dst->stack;
	stack_dst->stack = stack_src->stack;
	stack_src->stack = src_second;
	stack_dst->size = ft_lstsize(stack_dst->stack);
	stack_src->size = ft_lstsize(stack_src->stack);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_b->stack)
		return ;
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a->stack)
		return ;
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
