/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:35:31 by mrios-es          #+#    #+#             */
/*   Updated: 2025/01/21 20:15:36 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	rotate(stack_a, DOWN);
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	rotate(stack_b, DOWN);
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, DOWN);
	rotate(stack_b, DOWN);
	ft_printf("rrr\n");
}
