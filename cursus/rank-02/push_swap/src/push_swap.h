/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:41:29 by mrios-es          #+#    #+#             */
/*   Updated: 2025/02/16 16:30:10 by mrios-es         ###   ########.fr       */
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

// sort_utils.c
int		get_right_position(int number, t_stack *stack_b);
int		calculate_steps(int index_a, int index_b, int sa_size, int sb_size);
void	update_cheapest(int i, int steps, int *min_steps, int *cheapest_index);
int		calculate_cheapest(t_stack *stack_a, t_stack *stack_b);

// sort_utils2.c
int		rotate_ab(int index_a, int index_b, t_stack *sa, t_stack *sb);
void	rotate_a(int index, t_stack *stack_a);
void	rotate_b(int index, t_stack *stack_b);
void	execute_steps(int index_a, int index_b, t_stack *sa, t_stack *sb);
int		find_smallest_bigger_pos(int number, t_stack *stack);

// sort.c
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
