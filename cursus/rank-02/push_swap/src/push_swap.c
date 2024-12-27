/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:33:01 by mrios-es          #+#    #+#             */
/*   Updated: 2024/12/27 16:28:52 by mrios-es         ###   ########.fr       */
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

	stack_a->stack = init_args(argc, argv);
	if (!stack_a->stack)
		return (EXIT_FAILURE);
	i = 0;
	while (stack_a->stack[i])
		i++;
	stack_a->size = i;
	stack_b->size = stack_a->size;
	stack_b->stack = ft_calloc(stack_a->size + 1, sizeof(int));
	if (!stack_b->stack)
		return (free(stack_a->stack), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	shift(t_stack *stack, int direction)
{
	int	head;

	(void)direction;
	head = stack->stack[0];

	print_stacks(stack, stack);

	ft_memmove(stack->stack, stack->stack, stack->size - 1);

	print_stacks(stack, stack);

	stack->stack[stack->size - 1] = head;
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (validate_args(argc, argv))
		return (ft_printf("Error\n"));
	if (init_stacks(&stack_a, &stack_b, argc, argv))
		return (ft_printf("Failed initializing stacks!\n"));
	print_stacks(&stack_a, &stack_b);
	// ft_printf("testing swaps:\n");
	// s(&stack_a, A);
	// print_stacks(&stack_a, &stack_b);
	// s(&stack_b, B);
	// print_stacks(&stack_a, &stack_b);
	// ss(&stack_a, &stack_b);
	// print_stacks(&stack_a, &stack_b);
	shift(&stack_a, DOWN);
	print_stacks(&stack_a, &stack_b);
	ft_printf("ok\n");
	return (EXIT_SUCCESS);
}
