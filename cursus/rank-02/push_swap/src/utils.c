/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:53:06 by mrios-es          #+#    #+#             */
/*   Updated: 2024/12/26 12:54:17 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
