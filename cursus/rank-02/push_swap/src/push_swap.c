/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:33:01 by mrios-es          #+#    #+#             */
/*   Updated: 2025/02/02 22:22:56 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	*init_args(int argc, char **argv)
// {
// 	char	**args;
// 	int		*numbers;
// 	int		should_split;
// 	int		i;

// 	args = argv + 1;
// 	should_split = argc == 2;
// 	if (should_split)
// 		args = ft_split(argv[1], ' ');
// 	if (!args)
// 		return (NULL);
// 	i = 0;
// 	while (args[i])
// 		i++;
// 	numbers = ft_calloc(i + 1, sizeof(int));
// 	if (!numbers)
// 	{
// 		if (should_split)
// 			free_str_array(args);
// 		return (NULL);
// 	}
// 	strarr_to_intarr(args, numbers);
// 	if (should_split)
// 		free_str_array(args);
// 	return (numbers);
// }

void	del(int content)
{
	(void)content;
}

t_list	*init_args(int argc, char **argv)
{
	char	**args;
	t_list	*numbers;
	t_list	*aux;
	int		should_split;
	int		i;

	args = argv + 1;
	should_split = argc == 2;
	if (should_split)
		args = ft_split(argv[1], ' ');
	if (!args)
		return (NULL);
	numbers = NULL;
	i = 0;
	while (args[i])
	{
		aux = ft_lstnew(ft_atoi(args[i]));
		if (!aux)
		{
			ft_lstclear(&numbers, del);
			break ;
		}
		ft_lstadd_back(numbers, aux);
		i++;
	}
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
	stack_a->total = i;
	stack_b->total = stack_a->total;
	stack_a->size = stack_a->total;
	stack_b->size = 0;
	stack_b->stack = ft_calloc(stack_a->size + 1, sizeof(int));
	if (!stack_b->stack)
		return (free(stack_a->stack), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	min_value(t_stack *stack)
{
	int		min;
	t_list	*curr;

	curr = stack->stack;
	min = curr->content;
	while (curr)
	{
		if (curr->content < min)
			min = curr->content;
		curr = curr->next;
	}
	return (min);
}

int	max_value(t_stack *stack)
{
	int		max;
	t_list	*curr;

	curr = stack->stack;
	max = curr->content;
	while (curr)
	{
		if (curr->content > max)
			max = curr->content;
		curr = curr->next;
	}
	return (max);
}

/*
123 - none
132 - rra - 213 - sa - 123
213 - sa  - 123
231 - rra - 123
312 - ra  - 123
321 - sa  - 231 - rra - 123
*/
void	sort_3(t_stack *stack_a)
{
	int	min;
	int	max;
	int	first;
	int	second;
	int	third;

	min = min_value(stack_a);
	max = max_value(stack_a);
	first = stack_a->stack->content;
	second = stack_a->stack->next->content;
	third = stack_a->stack->next->next->content;
	if (first == min && second == max)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (second == min && third == max)
		sa(stack_a);
	else if (second == max && third == min)
		rra(stack_a);
	else if (first == max && second == min)
		ra(stack_a);
	else if (first == max && third == min)
		return (sa(stack_a), rra(stack_a));
}

void	insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	while (stack_a->size > 3 && !is_sorted(stack_a))
	{
		// for each element in A
			// calculate cheapest element to push to B by saving the steps needed
			// update the reference to the cheapest when new cheapest is found
		// execute the steps of the cheapest
	}
}

void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 3 && !is_sorted(stack_a))
		pb(stack_a, stack_b);
	if (stack_a->size > 3 && !is_sorted(stack_a))
		pb(stack_a, stack_b);

	// keep pushing into B until A has size 3
	insertion_sort(stack_a, stack_b);

	sort_3(stack_a);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
		sa(stack_a);
	turk_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (EXIT_SUCCESS);
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
