/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:37:23 by mrios-es          #+#    #+#             */
/*   Updated: 2025/02/03 21:55:17 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*s;
	t_list	*second;

	s = *stack;
	second = s->stack->next;
	s->stack->next = second->next;
	second->next = s->stack;
	s->stack = second;
}

void	sa(t_stack *stack_a)
{
	swap(&stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	swap(&stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(&stack_a);
	swap(&stack_b);
	ft_printf("ss\n");
}
