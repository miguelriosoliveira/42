/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:20:15 by mrios-es          #+#    #+#             */
/*   Updated: 2025/01/21 21:22:40 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *stack_dst, t_stack *stack_src)
{
	int	size;
	int	aux;

	if (stack_src->size == 0)
		return ;
	aux = stack_src->stack[0];
	rotate(stack_src, UP);
	stack_src->size--;
	stack_src->stack[stack_src->size] = 0;
	if (stack_dst->size > 0)
	{
		size = sizeof(int) * (stack_dst->size);
		ft_memmove(stack_dst->stack + 1, stack_dst->stack, size);
	}
	stack_dst->stack[0] = aux;
	stack_dst->size++;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
