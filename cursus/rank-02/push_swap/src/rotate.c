/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:35:31 by mrios-es          #+#    #+#             */
/*   Updated: 2025/01/21 20:16:43 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, int direction)
{
	int	aux;
	int	size;

	size = sizeof(int) * (stack->size - 1);
	if (direction == UP)
	{
		aux = stack->stack[0];
		ft_memmove(stack->stack, stack->stack + 1, size);
		stack->stack[stack->size - 1] = aux;
	}
	else
	{
		aux = stack->stack[stack->size - 1];
		ft_memmove(stack->stack + 1, stack->stack, size);
		stack->stack[0] = aux;
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
