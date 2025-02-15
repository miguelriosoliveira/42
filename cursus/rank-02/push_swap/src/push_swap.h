/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:41:29 by mrios-es          #+#    #+#             */
/*   Updated: 2025/02/15 23:21:37 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define UP 0
# define DOWN 1

typedef struct s_stack
{
	int		size;
	t_list	*stack;
}	t_stack;

// push.c
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

// reverse_rotate.c
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// rotate.c
void	rotate(t_stack *stack, int direction);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

// sort.c
void	sort_3(t_stack *stack_a);
int		get_right_position(int number, t_stack *stack_b);
void	execute_steps(int index, int number, t_stack *sa, t_stack *sb);
int		insertion_sort(t_stack *stack_a, t_stack *stack_b);
int		find_smallest_bigger_pos(int number, t_stack *stack);
void	push_back_to_a(t_stack *stack_a, t_stack *stack_b);
void	turk_sort(t_stack *stack_a, t_stack *stack_b);
void	sort(t_stack *stack_a, t_stack *stack_b);

// stack.c
int		get_index(int number, t_stack *stack);
int		get_value(int index, t_stack *stack);
int		min_value(t_stack *stack);
int		max_value(t_stack *stack);

// swap.c
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

// utils.c
int		is_sorted(t_stack *stack);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
void	free_str_array(char **arr);

// validation.c
int		validate_args(int argc, char **argv);

#endif
