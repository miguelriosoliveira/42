/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:33:01 by mrios-es          #+#    #+#             */
/*   Updated: 2025/02/04 22:16:20 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(void *content)
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
		aux = ft_lstnew((void *)ft_atoi(args[i]));
		if (!aux)
		{
			ft_lstclear(&numbers, del);
			break ;
		}
		ft_lstadd_back(&numbers, aux);
		i++;
	}
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

int	min_value(t_stack *stack)
{
	int		*min;
	int		*curr_content;
	t_list	*curr;

	curr = stack->stack;
	min = curr->content;
	while (curr)
	{
		curr_content = curr->content;
		if (*curr_content < *min)
			*min = *curr_content;
		curr = curr->next;
	}
	return (*min);
}

int	max_value(t_stack *stack)
{
	int		*max;
	int		*curr_content;
	t_list	*curr;

	curr = stack->stack;
	max = curr->content;
	while (curr)
	{
		curr_content = curr->content;
		if (*curr_content > *max)
			*max = *curr_content;
		curr = curr->next;
	}
	return (*max);
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
	int	*first;
	int	*second;
	int	*third;

	min = min_value(stack_a);
	max = max_value(stack_a);
	first = stack_a->stack->content;
	second = stack_a->stack->next->content;
	third = stack_a->stack->next->next->content;
	if (*first == min && *second == max)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (*second == min && *third == max)
		sa(stack_a);
	else if (*second == max && *third == min)
		rra(stack_a);
	else if (*first == max && *second == min)
		ra(stack_a);
	else if (*first == max && *third == min)
		return (sa(stack_a), rra(stack_a));
}

int	count_steps(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*curr_a;
	t_list	*curr_b;
	int		i;
	int		j;
	int		max_b;
	int		max_b_index;
	int		min_steps;

	min_steps = INT_MAX;
	i = 0;
	curr_a = stack_a->stack;
	while (curr_a)
	{
		// find largest number smaller than curr_a
		j = 0;
		curr_b = stack_b->stack;
		max_b = curr_b;
		while (curr_b)
		{
			if (curr_b->content < curr_a->content && curr_b->content > max_b)
			{
				max_b = curr_b->content;
				max_b_index = j;
			}
			j++;
			curr_b = curr_b->next;
		}
		// min_steps = d(curr_a->content, stack_a) + d(max_b, stack_b);
		if (i + max_b_index < min_steps)
			min_steps = i + max_b_index;
		i++;
		curr_a = curr_a->next;
	}
}

int	insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*curr;
	t_list	*steps;
	int	i;
	int	cheapest;
	int	cheapest_index;

	(void)stack_b;
	while (stack_a->size > 3 && !is_sorted(stack_a))
	{
		// for each element in A
			// calculate cheapest element to push to B by saving the steps needed
			// update the reference to the cheapest when new cheapest is found
		// execute the steps of the cheapest
		steps = ft_lstmap(stack_a->stack, count_steps, del);
		if (!steps)
			return (EXIT_FAILURE);
		curr = steps;
		cheapest = curr->content;
		i = 0;
		while (curr)
		{
			if (curr->content < cheapest)
			{
				cheapest = curr->content;
				cheapest_index = i;
			}
			i++;
			curr = curr->next;
		}
		ft_lstclear(&steps, del);
	}
	return (EXIT_SUCCESS);
}

void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 3 && !is_sorted(stack_a))
		pb(stack_a, stack_b);
	if (stack_a->size > 3 && !is_sorted(stack_a))
		pb(stack_a, stack_b);

	// keep pushing into B until A has size 3
	if (insertion_sort(stack_a, stack_b));

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
