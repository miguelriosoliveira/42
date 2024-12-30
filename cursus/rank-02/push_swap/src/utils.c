/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:53:06 by mrios-es          #+#    #+#             */
/*   Updated: 2024/12/30 15:56:49 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->stack[i] && stack->stack[i + 1])
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	ft_printf("stack size: %d\n", stack_a->size);
	i = 0;
	while (stack_a->stack[i])
	{
		ft_printf("[%d]\t%d\t%d\n", i, stack_a->stack[i], stack_b->stack[i]);
		i++;
	}
	ft_printf("\t_\t_\n");
	ft_printf("\ta\tb\n");
	ft_printf("Is sorted? ");
	if (is_sorted(stack_a))
		ft_printf("Yes\n");
	else
		ft_printf("No\n");
}

void	free_str_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	strarr_to_intarr(char **strarr, int *intarr)
{
	int	i;

	i = 0;
	while (strarr[i])
	{
		intarr[i] = ft_atoi(strarr[i]);
		i++;
	}
}
