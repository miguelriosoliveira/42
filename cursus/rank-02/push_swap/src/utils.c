/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:53:06 by mrios-es          #+#    #+#             */
/*   Updated: 2025/02/16 20:38:53 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_list	*curr;

	curr = stack->stack;
	while (curr && curr->next)
	{
		if ((int)(unsigned long)curr->content
			> (int)(unsigned long)curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*curr_a;
	t_list	*curr_b;
	int		i;

	ft_printf("stack_a #: %d\nstack_b #: %d\n", stack_a->size, stack_b->size);
	curr_a = stack_a->stack;
	curr_b = stack_b->stack;
	i = 0;
	while (curr_a || curr_b)
	{
		ft_printf("[%d]\t", i++);
		if (curr_a)
		{
			ft_printf("%d", curr_a->content);
			curr_a = curr_a->next;
		}
		ft_printf("\t");
		if (curr_b)
		{
			ft_printf("%d", curr_b->content);
			curr_b = curr_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("\t_\t_\n\tA\tB\nIs sorted? %d\n", is_sorted(stack_a));
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
