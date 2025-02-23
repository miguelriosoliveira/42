/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:33:01 by mrios-es          #+#    #+#             */
/*   Updated: 2025/02/23 11:32:50 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	noop(void *content)
{
	(void)content;
}

void	to_list(char **args, t_list **numbers)
{
	t_list	*aux;
	int		i;

	i = 0;
	while (args[i])
	{
		aux = ft_lstnew((void *)ft_atoi(args[i]));
		if (!aux)
		{
			ft_lstclear(numbers, noop);
			break ;
		}
		ft_lstadd_back(numbers, aux);
		i++;
	}
}

t_list	*init_args(int argc, char **argv)
{
	char	**args;
	t_list	*numbers;
	int		should_split;

	args = argv + 1;
	should_split = argc == 2;
	if (should_split)
		args = ft_split(argv[1], ' ');
	if (!args)
		return (NULL);
	numbers = NULL;
	to_list(args, &numbers);
	if (should_split)
		free_str_array(args);
	return (numbers);
}

int	init_stacks(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	stack_a->stack = init_args(argc, argv);
	if (!stack_a->stack)
		return (EXIT_FAILURE);
	stack_b->stack = NULL;
	stack_a->size = ft_lstsize(stack_a->stack);
	stack_b->size = 0;
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (validate_args(argc, argv)
		|| init_stacks(&stack_a, &stack_b, argc, argv))
		return (ft_putstr_fd("Error\n", STDERR_FILENO));
	sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a.stack, noop);
	ft_lstclear(&stack_b.stack, noop);
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
