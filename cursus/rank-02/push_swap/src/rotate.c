/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:35:31 by mrios-es          #+#    #+#             */
/*   Updated: 2024/12/30 15:35:54 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack, int direction)
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

void	r(t_stack *stack, int direction)
{
	rotate(stack, direction);
	if (direction == DOWN)
		ft_printf("r");
	ft_printf("r%c\n", stack->id);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int direction)
{
	rotate(stack_a, direction);
	rotate(stack_b, direction);
	if (direction == DOWN)
		ft_printf("r");
	ft_printf("rr\n");
}
