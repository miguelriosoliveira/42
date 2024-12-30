/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:37:23 by mrios-es          #+#    #+#             */
/*   Updated: 2024/12/30 15:37:24 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	aux;

	if (stack->size <= 1)
		return ;
	aux = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = aux;
}

void	s(t_stack *stack)
{
	swap(stack);
	ft_printf("s%c\n", stack->id);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
