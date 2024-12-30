/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:41:29 by mrios-es          #+#    #+#             */
/*   Updated: 2024/12/30 15:39:36 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define A 'a'
# define B 'b'

# define UP 0
# define DOWN 1

typedef struct s_stack
{
	char	id;
	int		size;
	int		total;
	int		*stack;
}	t_stack;

// rotate.c
void	r(t_stack *stack, int direction);
void	rr(t_stack *stack_a, t_stack *stack_b, int direction);

// swap.c
void	s(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);

// utils.c
int		is_sorted(t_stack *stack);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
void	free_str_array(char **arr);
void	strarr_to_intarr(char **strarr, int *intarr);

// validation.c
int		validate_args(int argc, char **argv);

#endif
