/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:33:01 by mrios-es          #+#    #+#             */
/*   Updated: 2025/01/25 23:27:38 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_args(int argc, char **argv)
{
	char	**args;
	int		*numbers;
	int		should_split;
	int		i;

	args = argv + 1;
	should_split = argc == 2;
	if (should_split)
		args = ft_split(argv[1], ' ');
	if (!args)
		return (NULL);
	i = 0;
	while (args[i])
		i++;
	numbers = ft_calloc(i + 1, sizeof(int));
	if (!numbers)
	{
		if (should_split)
			free_str_array(args);
		return (NULL);
	}
	strarr_to_intarr(args, numbers);
	if (should_split)
		free_str_array(args);
	return (numbers);
}

int	init_stacks(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	int	i;

	stack_a->id = A;
	stack_b->id = B;
	stack_a->stack = init_args(argc, argv);
	if (!stack_a->stack)
		return (EXIT_FAILURE);
	i = 0;
	while (stack_a->stack[i])
		i++;
	stack_a->total = i;
	stack_b->total = stack_a->total;
	stack_a->size = stack_a->total;
	stack_b->size = 0;
	stack_b->stack = ft_calloc(stack_a->size + 1, sizeof(int));
	if (!stack_b->stack)
		return (free(stack_a->stack), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	sort_2(t_stack *stack_a)
{
	if (!is_sorted(stack_a))
		sa(stack_a);
}

int	find_smallest_index(t_stack *stack)
{
	int	i;
	int	smallest;
	int	smallest_index;

	smallest = INT_MAX;
	smallest_index = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] < smallest)
		{
			smallest = stack->stack[i];
			smallest_index = i;
		}
		i++;
	}
	return (smallest_index);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	smallest_index;

	i = stack_a->size;
	while (i--)
	{
		smallest_index = find_smallest_index(stack_a);
		if (smallest_index < stack_a->size / 2)
			while (smallest_index--)
				ra(stack_a);
		else
			while (smallest_index < stack_a->size)
			{
				rra(stack_a);
				smallest_index++;
			}
		pb(stack_a, stack_b);
	}
	i = stack_b->size;
	while (i--)
		pa(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (validate_args(argc, argv))
		return (ft_printf("Error\n"));
	if (init_stacks(&stack_a, &stack_b, argc, argv))
		return (ft_printf("Failed initializing stacks!\n"));
	sort(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}

/*
print_stacks(&stack_a, &stack_b);
sa(&stack_a);
print_stacks(&stack_a, &stack_b);
sa(&stack_a);
print_stacks(&stack_a, &stack_b);

pb(&stack_a, &stack_b);
print_stacks(&stack_a, &stack_b);
pb(&stack_a, &stack_b);
print_stacks(&stack_a, &stack_b);
pb(&stack_a, &stack_b);
print_stacks(&stack_a, &stack_b);
pb(&stack_a, &stack_b);
print_stacks(&stack_a, &stack_b);

sb(&stack_b);
print_stacks(&stack_a, &stack_b);
sb(&stack_b);
print_stacks(&stack_a, &stack_b);

rb(&stack_b);
print_stacks(&stack_a, &stack_b);
rb(&stack_b);
print_stacks(&stack_a, &stack_b);
rb(&stack_b);
print_stacks(&stack_a, &stack_b);

pa(&stack_a, &stack_b);
print_stacks(&stack_a, &stack_b);
pa(&stack_a, &stack_b);
print_stacks(&stack_a, &stack_b);
pa(&stack_a, &stack_b);
print_stacks(&stack_a, &stack_b);
pa(&stack_a, &stack_b);
print_stacks(&stack_a, &stack_b);

ra(&stack_a);
print_stacks(&stack_a, &stack_b);
ra(&stack_a);
print_stacks(&stack_a, &stack_b);
ra(&stack_a);
print_stacks(&stack_a, &stack_b);
*/
