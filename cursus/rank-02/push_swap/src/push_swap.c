/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:33:01 by mrios-es          #+#    #+#             */
/*   Updated: 2025/02/06 21:36:56 by mrios-es         ###   ########.fr       */
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

int	get_zero(void)
{
	return (0);
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
	int		min;
	int		content;
	t_list	*curr;

	curr = stack->stack;
	min = INT_MAX;
	while (curr)
	{
		content = (int)(unsigned long)curr->content;
		if (content < min)
			min = content;
		curr = curr->next;
	}
	return (min);
}

int	max_value(t_stack *stack)
{
	int		max;
	int		content;
	t_list	*curr;

	curr = stack->stack;
	max = INT_MIN;
	while (curr)
	{
		content = (int)(unsigned long)curr->content;
		if (content > max)
			max = content;
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
	first = (int)(unsigned long)stack_a->stack->content;
	second = (int)(unsigned long)stack_a->stack->next->content;
	third = (int)(unsigned long)stack_a->stack->next->next->content;
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

int	get_right_position(int number, t_stack *stack_b)
{
	t_list	*curr;
	int		i;
	int		max_b;
	int		max_b_index;
	int		content;

	max_b = INT_MIN;
	i = 0;
	curr = stack_b->stack;
	while (curr)
	{
		content = (int)(unsigned long)curr->content;
		if (content < number && content > max_b)
		{
			max_b = content;
			max_b_index = i;
		}
		curr = curr->next;
	}
	return (max_b_index);
}

void	execute_steps(int index, int number, t_stack *stack_a, t_stack *stack_b)
{
	int	steps_b;

	steps_b = get_right_position(number, stack_b);
	while (index--)
		ra(stack_a);
	while (steps_b--)
		rb(stack_b);
	pb(stack_a, stack_b);
}

int	insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*curr;
	int		steps;
	int		i;
	int		min_steps;
	int		cheapest;
	int		cheapest_index;

	(void)stack_b;
	while (stack_a->size > 3 && !is_sorted(stack_a))
	{
		// for each element in A
			// calculate how many steps are needed to push to B in the right position
			// save index of the cheapest when new cheapest is found
		// execute the steps of the cheapest
		curr = stack_a->stack;
		min_steps = INT_MAX;
		i = 0;
		while (curr)
		{
			steps = i + get_right_position((int)(unsigned long)curr->content, stack_b);
			if (steps < min_steps)
			{
				min_steps = steps;
				cheapest = (int)(unsigned long)curr->content;
				cheapest_index = i;
			}
			i++;
			curr = curr->next;
		}
		execute_steps(cheapest_index, cheapest, stack_a, stack_b);
	}
	return (EXIT_SUCCESS);
}

int	get_index(int number, t_stack *stack)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = stack->stack;
	while (curr)
	{
		if ((int)(unsigned long)curr->content == number)
			return (i);
		i++;
		curr = curr->next;
	}
	return (-1);
}

int	find_smallest_bigger_pos(int number, t_stack *stack)
{
	int		i;
	int		index;
	int		elem;
	t_list	*curr;

	i = 0;
	curr = stack->stack;
	elem = (int)(unsigned long)curr->content;
	index = -1;
	while (curr)
	{
		if ((int)(unsigned long)curr->content > number && (int)(unsigned long)curr->content < elem)
		{
			elem = (int)(unsigned long)curr->content;
			index = i;
		}
		i++;
		curr = curr->next;
	}
	if (index >= 0)
		return (index);
	return (get_index(min_value(stack), stack));
}

void	push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	index;

	while (stack_b->stack)
	{
		// find index of proper element (smallest element bigger than current)
		index = find_smallest_bigger_pos((int)(unsigned long)stack_b->stack->content, stack_a);
		// if index <= stack_a.size/2 rotate A until proper element is on top
		if (index <= stack_a->size)
			while (index--)
				ra(stack_a);
		// else reverse rotate A until proper element is on top
		else
			while (index++ < stack_a->size)
				rra(stack_a);
		// push from B to A
		pa(stack_a, stack_b);
	}
}

void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_elem_index;

	// push first 2 elements to B
	if (stack_a->size > 3 && !is_sorted(stack_a))
		pb(stack_a, stack_b);
	if (stack_a->size > 3 && !is_sorted(stack_a))
		pb(stack_a, stack_b);
	// keep pushing to B until A has size 3
	insertion_sort(stack_a, stack_b);
	// sort remaining 3
	sort_3(stack_a);
	// push back from B to A
	push_back_to_a(stack_a, stack_b);
	// rotate A until minimum element is on top
	min_elem_index = get_index(min_value(stack_a), stack_a);
	if (min_elem_index <= stack_a->size)
		while (min_elem_index--)
			ra(stack_a);
	// else reverse rotate A until proper element is on top
	else
		while (min_elem_index++ < stack_a->size)
			rra(stack_a);
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
	print_stacks(&stack_a, &stack_b);
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
